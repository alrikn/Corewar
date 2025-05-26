/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** lfork
*/

#include "my.h"
#include "op.h"
#include "struct.h"

static finger_t *initialize_finger(int pc)
{
    finger_t *node = malloc(sizeof(finger_t));

    node->wait_cycle = 0;
    node->pc = pc;
    node->next = NULL;
    node->func = NULL;
    my_memset(node->register_buf, 0, REG_NUMBER);
    return node;
}

int op_lfork(core_t *core, finger_t *champ, func_t *func)
{
    int pc_pos = pc_update(champ->pc +
    (func->args[0].value_type.short_val));
    finger_t *new_finger = initialize_finger(pc_pos);
    finger_t *current = champ;

    if (!new_finger) {
        return 84;
    }
    while (current->next)
        current = current->next;
    current->next = new_finger;
    champ->wait_cycle = 800;
    return 0;
}
