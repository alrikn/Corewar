/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** lld
*/

#include "my.h"
#include "op.h"
#include "struct.h"

int op_lld(core_t *core, finger_t *champ, func_t *node)
{
    int pc_pos;

    if (node->args[0].type == DIRECT)
        pc_pos = pc_update(champ->pc +
    node->args[0].value_type.int_val);
    if (node->args[0].type == INDIRECT)
        pc_pos = pc_update(champ->pc +
    node->args[0].value_type.short_val);
    champ->register_buf[node->args[1].value_type.byte - 1] = read_int_array(
    core->array, pc_pos);
    champ->wait_cycle = 5;
    champ->carry = true;
    return 0;
}
