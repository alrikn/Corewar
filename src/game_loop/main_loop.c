/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** main_loop
*/

#include "my.h"
#include "op.h"
#include "struct.h"

static const op_func_t op_table[] = {
    [LIVE] = op_live,
    [LD] = op_ld,
    [ST] = op_st,
    [STI] = op_sti,
    [ZJMP] = op_zjmp,
    [AFF] = op_aff,
    [ADD] = op_add,
    [SUB] = op_sub,
    [FORK] = op_fork,
    [LFORK] = op_lfork,
    [LLD] = op_lld,
    [AND] = op_and,
    [OR] = op_or,
    [XOR] = op_xor,
    [LDI] = op_ldi,
    [LLDI] = op_lldi,
};

int player_turn(core_t *core, finger_t *head)
{
    int func_num = head->func->func_num;

    if (func_num < 1 || func_num > MAX_FUNC) {
        return 84;
    }
    if (op_table[func_num]) {
        return op_table[func_num](core, head, head->func);
    }
    my_cooler_putstr("this func hasn't been handled yet\n");
    return 84;
}

static void deal_with_dead_head(finger_t **champ)
{
    finger_t *dead_champ = *champ;

    *champ = dead_champ->next;
    if (dead_champ->func)
        free(dead_champ->func);
    free(dead_champ);
}

static void update_func(finger_t *entry, core_t *core)
{
    if (entry->func)
        player_turn(core, entry);
    free(entry->func);
    entry->func = read_map_func(core, &entry->pc);
}

static void go_through_heads(core_t *core, player_t *player)
{
    finger_t **current = &player->fing_head;
    finger_t *entry = *current;

    while (*current) {
        entry = *current;
        if (entry->wait_cycle > 0) {
            entry->wait_cycle--;
            current = &entry->next;
            continue;
        }
        update_func(entry, core);
        if (!entry->func) {
            my_cooler_putstr("a head died\n");
            deal_with_dead_head(current);
            continue;
        }
        entry->wait_cycle--;
        current = &entry->next;
    }
}

/*
** we go until only one player
*/
void execute_player(core_t *core, int cycle_live)
{
    player_t *player = core->player_head;

    while (player) {
        if (player->cycle_since_live > cycle_live || !player->fing_head) {
            my_cooler_putstr("a player died\n");
            kill_player(core, &player);
            core->num_of_players--;
            continue;
        }
        if (player->fing_head) {
            go_through_heads(core, player);
            player = player->next;
        }
    }
}

int main_loop(core_t *core)
{
    int cycle = CYCLE_TO_DIE;

    if (core->dump.dump)
        cycle = core->dump.dump_num;
    while (cycle > 0 && core->num_of_players > 1) {
        for (int i = cycle; i > 0 && core->num_of_players > 1; i--) {
            execute_player(core, cycle);
        }
        cycle -= CYCLE_DELTA;
    }
    if (core->player_head) {
        my_cooler_putstr("The player ");
        my_put_nbr(core->player_head->id);
        my_cooler_putstr("(");
        my_cooler_putstr(core->player_head->header.prog_name);
        my_cooler_putstr(")has won.\n");
        kill_player(core, &core->player_head);
    } else
        my_cooler_putstr("all players are dead\n");
    return 0;
}
