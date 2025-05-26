/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** zjmp
*/

#include "my.h"
#include "op.h"
#include "struct.h"

int op_zjmp(core_t *core, finger_t *champ, func_t *func)
{
    if (champ->carry) {
        champ->pc += func->args[0].value_type.short_val;
    }
    champ->wait_cycle = 20;
    return 0;
}
