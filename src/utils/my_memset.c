/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** my_memset
*/

#include <stdlib.h>

void *my_memset(void *ptr, int value, size_t num)
{
    unsigned char *p = ptr;

    while (num) {
        num--;
        *p = (unsigned char)value;
        p++;
    }
    return ptr;
}
