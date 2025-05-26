/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** coding_byte_parser
*/

#include "my.h"
#include "op.h"
#include "struct.h"

/*
** as a reminder if SOMEBODY wants to change this if statement:
** the fucntions with no coding byte are :
LIVE ZJMP FORK LFORK
*/
bool is_func_with_coding_byte(func_t *node)
{
    if (node->func_num == LIVE || node->func_num == ZJMP ||
    node->func_num == FORK || node->func_num == LFORK) {
        node->coding_byte = false;
        return false;
    }
    node->coding_byte = true;
    return true;
}

/*
** this code must only be launched if there is it is a func with a coding byte
** the coding bytes is contained in, guess what, a single byte
** this needs to be checked correctly
** here we also need set the type_t for every argument
*/
void coding_byte_handle(core_t *core, func_t *node, player_t *player)
{
    unsigned char byte;
    long test = fread(&byte, sizeof(char), 1, player->input);
    unsigned int pair[4];

    if (test <= 0 || node->func_num <= 0 || node->func_num > AFF)
        core->error_occured = true;
    node->orig_coding_byte = byte;
    pair[0] = (byte >> 6) & 0x03;
    pair[1] = (byte >> 4) & 0x03;
    pair[2] = (byte >> 2) & 0x03;
    pair[3] = byte & 0x03;
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        node->args[i].type = pair[i];
        if (is_index_func(node) && node->args[i].type == DIRECT)
            node->args[i].type = INDEX_POS;
        if (!is_index_func(node) && node->args[i].type == INDEX_POS)
            node->args[i].type = DIRECT;
    }
}

int no_coding_byte_handle(core_t *core, func_t *node)
{
    if (node->func_num == LIVE) {
        node->args[0].type = DIRECT;
        node->args[1].type = NONE;
    }
    if (node->func_num == ZJMP || node->func_num == FORK ||
    node->func_num == LFORK) {
        node->args[0].type = INDEX_POS;
        node->args[1].type = NONE;
    }
    return 0;
}
