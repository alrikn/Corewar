/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_map
*/

#include "my.h"
#include "op.h"
#include "struct.h"

/*
** this code must only be launched if there is it is a func with a coding byte
** the coding bytes is contained in, guess what, a single byte
** this needs to be checked correctly
** here we also need set the type_t for every argument
*/
void coding_byte_array(core_t *core, func_t *node, int *pc)
{
    unsigned char byte = core->array[*pc];
    long test = core->array[*pc];
    unsigned int pair[4];

    if (test <= 0 || node->func_num <= 0 || node->func_num > AFF)
        core->error_occured = true;
    *pc = pc_update(*pc + 1);
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

int parse_argument_array(core_t *core, func_t *node, int i, int *pc)
{
    type_t type = node->args[i].type;

    switch (type) {
        case REGISTER:
            node->args[i].value_type.byte = core->array[*pc];
            return pc_update(*pc + 1);
        case INDIRECT:
        case INDEX_POS:
            node->args[i].value_type.short_val = read_short_array(core->array,
            *pc);
            return pc_update(*pc + 2);
        case DIRECT:
            node->args[i].value_type.int_val = read_int_array(core->array,
            *pc);
            return pc_update(*pc + 4);
        default:
            core->error_occured = true;
            return *pc + 1;
    }
}

/*
** register is checked before because it is easy to check
*/
func_t *check_argument_errors(func_t *func, const op_t *op)
{
    int arg_count = 0;

    while (arg_count < MAX_ARGS_NUMBER && func->args[arg_count].type != NONE) {
        if (func->args[arg_count].type == REGISTER &&
        (func->args[arg_count].value_type.byte < 1 ||
        func->args[arg_count].value_type.byte > REG_NUMBER))
            arg_count = MAX_ARGS_NUMBER + 1;
        arg_count++;
    }
    if (arg_count != op->nbr_args) {
        free(func);
        return NULL;
    }
    for (int i = 0; i < op->nbr_args; i++) {
        if ((func->args[i].type & op->type[i]) == 0) {
            free(func);
            return NULL;
        }
    }
    return func;
}

/*
**we checjk for errors, if there are any, we free and return NULL
*/
func_t *check_func_error(func_t *func)
{
    const op_t *op = NULL;

    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (op_tab[i].func_num == func->func_num) {
            op = &op_tab[i];
            break;
        }
    }
    if (op == NULL) {
        free(func);
        return NULL;
    }
    return check_argument_errors(func, op);
}

/*
** you give it a pos in the array and it gives back null if the func is wrong
*/
func_t *read_map_func(core_t *core, int *pc)
{
    func_t *node = malloc(sizeof(func_t));

    *pc = *pc % MEM_SIZE;
    node->func_num = core->array[*pc];
    *pc = pc_update(*pc + 1);
    if (node->func_num <= 0 || node->func_num > AFF) {
        free(node);
        return NULL;
    }
    if (is_func_with_coding_byte(node)) {
        coding_byte_array(core, node, pc);
    } else {
        no_coding_byte_handle(core, node);
    }
    for (int i = 0; i < MAX_ARGS_NUMBER && node->args[i].type != NONE; i++)
        *pc = parse_argument_array(core, node, i, pc);
    return check_func_error(node);
}
