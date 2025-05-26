/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** aff
*/

#include "my.h"
#include "struct.h"
#include <unistd.h>

/*
** Function for aff operator, takes 1 register as param
*/
int op_aff(core_t *core, finger_t *champ, func_t *node)
{
    int reg_index = node->args[0].value_type.byte -1;
    unsigned int value = champ->register_buf[reg_index];

    value = value % 256;
    if (value != 42) {
        write(STDOUT_FILENO, &value, 1);
    } else {
        value = '*';
        write(STDOUT_FILENO, &value, 1);
    }
    champ->wait_cycle = 2;
    return 0;
}
