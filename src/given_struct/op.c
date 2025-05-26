/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** op
*/
/*
** op.c for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Tue Mar 22 16:44:20 2011 Astek
*/

#include "struct.h"


/*
typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    type_t type[MAX_ARGS_NUMBER];
    char func_num;
    int nbr_cycles;
    char *comment;
} op_t;
*/
const op_t op_tab[] = {
    {"live", 1, {DIRECT}, 1, 10, "alive"},
    {"ld", 2, {DIRECT | INDIRECT, REGISTER}, 2, 5, "load"},
    {"st", 2, {REGISTER, INDIRECT | REGISTER}, 3, 5, "store"},
    {"add", 3, {REGISTER, REGISTER, REGISTER}, 4, 10, "addition"},
    {"sub", 3, {REGISTER, REGISTER, REGISTER}, 5, 10, "soustraction"},
    {"and", 3,
        {REGISTER | DIRECT | INDIRECT, REGISTER | INDIRECT | DIRECT, REGISTER},
        6, 6, "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3,
        {REGISTER | INDIRECT | DIRECT, REGISTER | INDIRECT | DIRECT, REGISTER},
        7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3,
        {REGISTER | INDIRECT | DIRECT, REGISTER | INDIRECT | DIRECT, REGISTER},
        8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {INDEX_POS}, 9, 20, "jump if zero"},
    {"ldi", 3, {REGISTER | INDEX_POS, INDEX_POS | REGISTER, REGISTER}, 10, 25,
        "load index"},
    {"sti", 3, {REGISTER, REGISTER | INDEX_POS, INDEX_POS | REGISTER}, 11, 25,
        "store index"},
    {"fork", 1, {INDEX_POS}, 12, 800, "fork"},
    {"lld", 2, {DIRECT | INDIRECT, REGISTER}, 13, 10, "long load"},
    {"lldi", 3, {REGISTER | INDEX_POS, INDEX_POS | REGISTER, REGISTER}, 14, 50,
        "long load index"},
    {"lfork", 1, {INDEX_POS}, 15, 1000, "long fork"},
    {"aff", 1, {REGISTER}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
};
