/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** contain
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static int my_strlen(char const *str)
{
    char const *ptr = str;
    int len = 0;

    if (!str)
        return 0;
    while (*ptr != '\0') {
        ptr++;
        len++;
    }
    return (len);
}

static int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        if (s1[i] == '\0' || s2[i] == '\0')
            break;
    }
    return 0;
}

bool contains(const char *big, const char *small)
{
    size_t big_len = my_strlen(big);
    size_t small_len = my_strlen(small);

    if (!big || !small)
        return false;
    if (small_len > big_len) {
        return false;
    }
    for (size_t i = 0; i <= big_len - small_len; i++) {
        if (my_strncmp(&big[i], small, small_len) == 0) {
            return true;
        }
    }
    return false;
}
