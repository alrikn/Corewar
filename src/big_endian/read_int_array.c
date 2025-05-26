/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_int_array
*/

#include "my.h"
#include "op.h"

int read_int_array(char *array, int index)
{
    return read_int(array[(index % MEM_SIZE)],
    array[((index + 1) % MEM_SIZE)],
    array[((index + 2) % MEM_SIZE)],
    array[((index + 3) % MEM_SIZE)]);
}
