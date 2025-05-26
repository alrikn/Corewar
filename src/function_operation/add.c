/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** add
*/

#include "my.h"

/*
  **Function for add operator
*/
int op_add(core_t *core, finger_t *champ, func_t *node)
{
    int i_one = node->args[0].value_type.byte -1;
    int i_two = node->args[1].value_type.byte -1;
    int i_three = node->args[2].value_type.byte -1;

    champ->register_buf[i_three] = champ->register_buf[i_one] +
    champ->register_buf[i_two];
    champ->carry = 1;
    champ->wait_cycle = 10;
    return 0;
}
