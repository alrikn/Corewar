/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** live
*/

#include "my.h"
#include "struct.h"

int op_live(core_t *core, finger_t *champ, func_t *func)
{
    player_t *player = core->player_head;

    while (player && player->id != func->args[0].value_type.int_val) {
        player = player->next;
    }
    if (player) {
        my_cooler_putstr("The player ");
        my_put_nbr(player->id);
        my_cooler_putstr("(");
        my_cooler_putstr(player->header.prog_name);
        my_cooler_putstr(")is alive.\n");
        player->num_of_live++;
        player->cycle_since_live = 0;
    }
    champ->wait_cycle = 10;
    return 0;
}
