/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** and
*/

#include "my.h"

static int get_parameter(core_t *core, finger_t *champ, func_t *node, int i)
{
    int i_one;
    short value;

    if (node->args[i].type == DIRECT)
        return node->args[i].value_type.int_val;
    if (node->args[i].type == REGISTER) {
        i_one = node->args[i].value_type.byte -1;
        return champ->register_buf[i_one];
    }
    value = node->args[i].value_type.short_val;
    return (int)value;
}

/*
** we need to perform a binary and
*/
int op_and(core_t *core, finger_t *champ, func_t *node)
{
    int i_result = node->args[2].value_type.byte - 1;
    int param_one = get_parameter(core, champ, node, 0);
    int param_two = get_parameter(core, champ, node, 1);
    int result = param_one & param_two;

    champ->register_buf[i_result] = result;
    champ->carry = (result == 0) ? 1 : 0;
    champ->wait_cycle = 6;
    return 0;
}
