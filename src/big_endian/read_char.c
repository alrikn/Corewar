/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_char
*/

#include <stdio.h>

char read_char(FILE *input)
{
    char byte;

    fread(&byte, sizeof(char), 1, input);
    return byte;
}
