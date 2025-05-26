/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** sti
*/

#include "my.h"
#include "op.h"
#include "struct.h"

int op_sti(core_t *core, finger_t *champ, func_t *func)
{
    int load_from = champ->register_buf[func->args[0].value_type.byte - 1];
    short index;
    int result = 0;

    if (func->args[1].type == REGISTER) {
        result += champ->register_buf[func->args[1].value_type.byte - 1];
    } else {
        result += (func->args[1].value_type.short_val);
    }
    if (func->args[2].type == REGISTER) {
        result += champ->register_buf[func->args[2].value_type.byte - 1];
    } else {
        result += (func->args[2].value_type.short_val);
    }
    index = champ->pc + (result % IDX_MOD);
    write_int_array(core->array, index, load_from);
    champ->wait_cycle = 25;
    return 0;
}
