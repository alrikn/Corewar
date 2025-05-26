/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_int
*/

#include <stdint.h>

int32_t read_int(uint8_t one, uint8_t two, uint8_t three, uint8_t four)
{
    return (int32_t)((one << 24) | (two << 16) | (three << 8) | four);
}
