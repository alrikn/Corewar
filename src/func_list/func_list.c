/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** func_list
*/

#include "my.h"
#include "struct.h"

/*
** This is a function to check if an index given is a function as not
** all of them are.
*/
const func_map_t func_map_index[] = {
    {"zjmp", ZJMP}, {"ldi", LDI}, {"sti", STI}, {"fork", FORK},
    {"lfork", LFORK}, {"lldi", LLDI}, {NULL, 0}
};

bool is_index_func(func_t *node)
{
    for (int i = 0; func_map_index[i].name; i++) {
        if (node->func_num == func_map_index[i].func) {
            node->calls_index = true;
            return true;
        }
    }
    node->calls_index = false;
    return false;
}
