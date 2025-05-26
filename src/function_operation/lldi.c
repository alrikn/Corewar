/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** op_lldi
*/


#include "my.h"
#include "op.h"
#include "struct.h"

static int get_parameter(core_t *core, finger_t *champ, func_t *node, int i)
{
    int i_one;

    if (node->args[i].type == REGISTER) {
        i_one = node->args[i].value_type.byte -1;
        return champ->register_buf[i_one];
    }
    return (int)node->args[i].value_type.short_val;
}

int op_lldi(core_t *core, finger_t *champ, func_t *node)
{
    int offset = get_parameter(core, champ, node, 0);
    int index = pc_update(champ->pc + (offset));
    short return_value = read_short_array(core->array, index);
    int aft_addition = (int)return_value + get_parameter(core, champ, node, 1);
    int result_index = node->args[2].value_type.byte -1;

    champ->register_buf[result_index] = aft_addition;
    champ->carry = true;
    return 0;
}
