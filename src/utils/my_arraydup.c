/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_array_dup
*/

#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
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

static char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = NULL;

    if (!src)
        return NULL;
    dest = malloc(len + 1);
    if (dest == NULL) {
        return NULL;
    }
    for (int n = 0; n < len; n++) {
        dest[n] = src[n];
    }
    dest[len] = '\0';
    return dest;
}

char **my_arraydup(const char **array)
{
    int array_len = 0;
    char **new_array = NULL;

    if (!array)
        return NULL;
    while (array[array_len])
        array_len++;
    if (array_len == 0)
        return NULL;
    new_array = malloc((array_len + 1) * sizeof(char *));
    if (!new_array)
        return NULL;
    for (int i = 0; i < array_len; i++) {
        new_array[i] = my_strdup(array[i]);
        if (!new_array[i])
            return NULL;
    }
    new_array[array_len] = NULL;
    return new_array;
}
