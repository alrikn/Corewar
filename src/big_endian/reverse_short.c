/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** reverse_short
*/


short my_reverse_short(unsigned short value)
{
    unsigned short result = 0;

    for (int i = 0; i < sizeof(short); i++) {
        result = (result << 8) + (value & 0xFF);
        value >>= 8;
    }
    return result;
}
