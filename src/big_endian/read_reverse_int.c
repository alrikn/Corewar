/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_reverse_int
*/

#include <stdio.h>

int read_rev_int(FILE *input)
{
    int num;
    int reverse;

    fread(&num, sizeof(int), 1, input);
    reverse = ((num >> 24) & 0x000000FF) |
    ((num >> 8) & 0x0000FF00) |
    ((num << 8) & 0x00FF0000) |
    ((num << 24) & 0xFF000000);
    return reverse;
}
