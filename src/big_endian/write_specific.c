/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** write_specific
*/

#include <stdio.h>
#include <stdint.h>

int write_4byt(FILE *file, int value)
{
    uint8_t bytes[4];

    bytes[0] = (value >> 24) & 0xFF;
    bytes[1] = (value >> 16) & 0xFF;
    bytes[2] = (value >> 8) & 0xFF;
    bytes[3] = value & 0xFF;
    return fwrite(bytes, 1, 4, file);
}

int write_2byt(FILE *file, short value)
{
    uint8_t bytes[2];

    bytes[0] = (value >> 8) & 0xFF;
    bytes[1] = value & 0xFF;
    return fwrite(bytes, 1, 2, file);
}

int write_coding_byte(FILE *file, short pairs[4])
{
    uint8_t byte = 0;

    byte |= (pairs[0] & 0b11) << 6;
    byte |= (pairs[1] & 0b11) << 4;
    byte |= (pairs[2] & 0b11) << 2;
    byte |= (pairs[3] & 0b11);
    return fwrite(&byte, 1, 1, file);
}
