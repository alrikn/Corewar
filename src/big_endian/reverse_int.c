/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** reverse_int
*/

int my_reverse_int(int num)
{
    int reverse = ((num >> 24) & 0x000000FF) |
    ((num >> 8) & 0x0000FF00) |
    ((num << 8) & 0x00FF0000) |
    ((num << 24) & 0xFF000000);

    return reverse;
}
