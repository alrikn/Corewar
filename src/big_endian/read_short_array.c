/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_short_array
*/

#include "my.h"

int read_short_array(char *array, int index)
{
    return read_short(array[(index % MEM_SIZE)],
    array[((index + 1) % MEM_SIZE)]);
}
