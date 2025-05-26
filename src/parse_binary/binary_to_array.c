/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** binary_to_array
*/

#include "my.h"
#include "struct.h"
#include <stdio.h>

/*
** the player original pc has to be alrady set to pretty far
*/
int binary_to_array(core_t *core, player_t *player)
{
    int parse_pc = player->PC;
    long read = 0;

    parse_header(core, player);
    while (!core->error_occured &&
    parse_pc - player->PC < player->header.prog_size) {
        read = fread(&core->array[parse_pc], sizeof(char), 1, player->input);
        if (read <= 0)
            core->error_occured = true;
        parse_pc = pc_update(parse_pc + 1);
    }
    return 0;
}
