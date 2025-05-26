/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** st
*/

#include "my.h"
#include "op.h"
#include "struct.h"


int op_st(core_t *core, finger_t *champ, func_t *func)
{
    int load_from = champ->register_buf[func->args[0].value_type.byte - 1];
    short index;

    if (func->args[1].type == REGISTER) {
        champ->register_buf[func->args[1].value_type.byte - 1] = load_from;
    } else {
        index = champ->pc + (func->args[1].value_type.short_val % IDX_MOD);
    }
    write_int_array(core->array, index, load_from);
    champ->wait_cycle = 5;
    return 0;
}
