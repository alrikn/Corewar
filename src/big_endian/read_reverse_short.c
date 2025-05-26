/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_reverse_short
*/

#include <stdio.h>


short read_rev_short(FILE *input)
{
    short num;
    unsigned short result = 0;

    fread(&num, sizeof(short), 1, input);
    for (int i = 0; i < sizeof(short); i++) {
        result = (result << 8) + (num & 0xFF);
        num >>= 8;
    }
    return result;
}
