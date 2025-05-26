/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** write_map
*/

#include "my.h"
#include "op.h"
#include "struct.h"

void write_int_array(char *array, unsigned int index, int value)
{
    index = index % MEM_SIZE;
    for (int i = 0; i < 4; i++) {
        array[(index + i) % MEM_SIZE] = (value >> (8 * (3 - i))) & 0xFF;
    }
}

void write_short_array(char *array, unsigned int index, short value)
{
    index = index % MEM_SIZE;
    for (int i = 0; i < 2; i++) {
        array[(index + i) % MEM_SIZE] = (value >> (8 * (1 - i))) & 0xFF;
    }
}
