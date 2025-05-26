/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** initialize
*/

#include "my.h"
#include "op.h"
#include "struct.h"

finger_t *head_initialize(core_t *core, int pc)
{
    finger_t *champ = malloc(sizeof(finger_t));

    champ->func = read_map_func(core, &pc);
    if (!champ->func) {
        my_cooler_putstr("first head is wrong\n");
        free(champ);
        return NULL;
    }
    my_memset(champ->register_buf, 0, REG_NUMBER);
    champ->wait_cycle = 0;
    champ->pc = pc;
    champ->next = NULL;
    return champ;
}

static bool is_taken(int *id_array, int new_id, int num)
{
    for (int i = 0; i < num; i++) {
        if (id_array[i] == new_id) {
            return true;
        }
    }
    return false;
}

/*
** id starts at 1, no negative id
*/
void initialize_id(core_t *core, int *id_array, player_t *player, int num)
{
    int new_id = 1;
    bool taken;

    if (player->id != -1) {
        id_array[num] = player->id;
        return;
    }
    while (true) {
        taken = is_taken(id_array, new_id, num);
        if (!taken)
            break;
        new_id++;
    }
    player->id = new_id;
    id_array[num] = new_id;
}

void print_player(player_t *player)
{
    my_cooler_putstr("ID = ");
    my_put_nbr(player->id);
    my_cooler_putstr("\tSize = ");
    my_put_nbr(player->header.prog_size);
    my_cooler_putstr("\tPC = ");
    my_put_nbr(player->PC);
    my_cooler_putstr("\tprog_name = ");
    my_cooler_putstr(player->header.prog_name);
    my_cooler_putstr("\n");
}

/*
** we put the player in the mem array and start there
*/
void initialize_players(core_t *core)
{
    player_t *current = core->player_head;
    int id_array[core->num_of_players];
    int num = 0;

    my_memset(core->array, 0, MEM_SIZE);
    while (current) {
        initialize_id(core, id_array, current, num);
        if (!current->special_pc) {
            current->PC = (num * (MEM_SIZE / core->num_of_players) % MEM_SIZE);
        }
        binary_to_array(core, current);
        print_player(current);
        current->fing_head = head_initialize(core, current->PC);
        current = current->next;
        num++;
    }
}
