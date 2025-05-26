/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** parse_header
*/

#include "my.h"
#include "op.h"
#include "struct.h"
#include <stdio.h>

/*
** we put all this in the given header
*/
int parse_header(core_t *core, player_t *player)
{
    player->header.magic = read_rev_int(player->input);
    if (player->header.magic != COREWAR_EXEC_MAGIC) {
        my_cooler_putstr("magic num is wrong\n");
        core->error_occured = true;
        return 84;
    }
    fread(player->header.prog_name, sizeof(char), PROG_NAME_LENGTH + 4,
    player->input);
    player->header.prog_size = read_rev_int(player->input);
    if (player->header.prog_size <= 0) {
        my_cooler_putstr("prog size negative or equal 0\n");
        core->error_occured = true;
        return 84;
    }
    fread(player->header.comment, sizeof(char),
    COMMENT_LENGTH + 4, player->input);
    return 0;
}
