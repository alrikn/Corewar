/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** pc_update
*/

#include "op.h"

long int pc_update(long pc)
{
    if (pc < 0) {
        pc += MEM_SIZE;
    }
    return pc % MEM_SIZE;
}
