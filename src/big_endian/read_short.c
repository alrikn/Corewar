/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_short
*/

#include <stdint.h>

int16_t read_short(uint8_t one, uint8_t two)
{
    return (int16_t)((one << 8) | two);
}
