/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** flag_hunting
*/

#include "my.h"
#include "op.h"
#include "struct.h"
#include <stdio.h>

/*
** this is global flag for printing mem
*/
static void handle_dump_flag(int argc, char **argv, core_t *core, int *i)
{
    core->dump.dump = true;
    if (*i + 1 < argc && my_is_num(argv[*i + 1])) {
        core->dump.dump_num = my_str_to_int(argv[*i + 1]);
        *i += 2;
        return;
    }
    core->dump.dump_num = CYCLE_TO_DIE;
    *i += 1;
}

static void handle_n_flag(char **argv, int *i, player_t *player)
{
    player->id = my_str_to_int(argv[*i + 1]);
    *i += 2;
}

static void handle_a_flag(char **argv, int *i, player_t *player)
{
    player->PC = my_str_to_int(argv[*i + 1]);
    player->special_pc = true;
    *i += 2;
}

static player_t *create_player(void)
{
    player_t *new = malloc(sizeof(player_t));

    new->id = -1;
    new->special_pc = false;
    new->current_byte_pos = 0;
    new->next = NULL;
    new->cycle_since_live = 0;
    new->num_of_live = 0;
    new->dead = false;
    new->fing_head = NULL;
    return new;
}

static void add_to_player_list(core_t *core, player_t *player)
{
    player->next = core->player_head;
    core->player_head = player;
    core->num_of_players++;
}

void deal_with_flags(int argc, char **argv, core_t *core, int *i)
{
    if (my_strcmp(argv[*i], "-dump") == 0) {
        handle_dump_flag(argc, argv, core, i);
    }
}

/*
** for -n and - a flags
*/
player_t *parse_flags(int argc, char **argv, core_t *core, int *i)
{
    player_t *player;

    player = create_player();
    while (*i < argc && argv[*i][0] == '-') {
        if (my_strcmp(argv[*i], "-n") == 0 && *i + 1 < argc &&
        my_is_num(argv[*i + 1])) {
            handle_n_flag(argv, i, player);
            continue;
        }
        if (my_strcmp(argv[*i], "-a") == 0 && *i + 1 < argc &&
        my_is_num(argv[*i + 1])) {
            handle_a_flag(argv, i, player);
            continue;
        }
        core->error_occured = true;
        free(player);
        return NULL;
    }
    return player;
}

/*
** Everywhere we parse flags
*/
void parse_players(int argc, char **argv, core_t *core, int *i)
{
    player_t *player;

    while (*i < argc && !core->error_occured) {
        player = parse_flags(argc, argv, core, i);
        if (!player)
            return;
        if (*i >= argc) {
            core->error_occured = true;
            free(player);
            return;
        }
        player->input = fopen(argv[*i], "r");
        if (!player->input) {
            core->error_occured = true;
            free(player);
            return;
        }
        add_to_player_list(core, player);
        *i += 1;
    }
}
