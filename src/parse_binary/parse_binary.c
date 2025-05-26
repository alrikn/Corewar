/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** parse_binary
*/

#include "my.h"
#include "op.h"
#include "struct.h"
#include <stdio.h>
#include <time.h>

/*
** here we check what type it is
** how many bytes it is and we parse them
** no need for abel name cus everything is done through indexes
*/
void parse_argument(core_t *core, func_t *node, int i, player_t *player)
{
    type_t type = node->args[i].type;

    switch (type) {
        case REGISTER:
            node->args[i].value_type.byte = read_char(player->input);
            return;
        case INDIRECT:
        case INDEX_POS:
            node->args[i].value_type.short_val = read_rev_short(player->input);
            return;
        case DIRECT:
            node->args[i].value_type.int_val = read_rev_int(player->input);
            return;
        default:
            core->error_occured = true;
            return;
    }
}

/*
** starts at 1 for the actual func byte
*/
void update_bytecount(core_t *core, func_t *node, player_t *player)
{
    node->num_bytes = 1;
    if (node->coding_byte)
        node->num_bytes++;
    for (int i = 0; i < MAX_ARGS_NUMBER && node->args[i].type != NONE; i++) {
        if (node->args[i].type == REGISTER)
            node->num_bytes += 1;
        if (node->args[i].type == INDIRECT || node->args[i].type == INDEX_POS)
            node->num_bytes += 2;
        if (node->args[i].type == DIRECT)
            node->num_bytes += 4;
    }
    player->current_byte_pos += node->num_bytes;
}

/*
** this should start at a function,
parse it in its entirety and add it to the list
** this is like concept art it needs to be heavily
modified to be actually useful
** TODO:
** for errorhandling make sure that the func is
only taking the arguments t should
*/
func_t *parse_func(core_t *core, player_t *player)
{
    func_t *node = malloc(sizeof(func_t));

    if (!node)
        return NULL;
    fread(&node->func_num, sizeof(char), 1, player->input);
    if (node->func_num <= 0 || node->func_num > AFF) {
        free(node);
        core->error_occured = true;
        return NULL;
    }
    if (is_func_with_coding_byte(node)) {
        coding_byte_handle(core, node, player);
    } else {
        no_coding_byte_handle(core, node);
    }
    for (int i = 0; i < MAX_ARGS_NUMBER && node->args[i].type != NONE; i++)
        parse_argument(core, node, i, player);
    update_bytecount(core, node, player);
    node->next = NULL;
    return node;
}

void add_to_func_list(core_t *core, func_t **head,
    func_t **last, player_t *player)
{
    func_t *new_node = parse_func(core, player);
    func_t *temp = new_node;

    if (!new_node)
        return;
    if (*head == NULL) {
        *head = new_node;
        *last = new_node;
    } else {
        temp = *last;
        temp->next = new_node;
        new_node->prev = temp;
        *last = new_node;
    }
}

int function_list_maker(core_t *core, player_t *player)
{
    parse_header(core, player);
    while (!core->error_occured &&
    player->current_byte_pos < player->header.prog_size) {
    }
    return 0;
}
