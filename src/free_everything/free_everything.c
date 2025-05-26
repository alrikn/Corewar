/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** free_everything
*/

#include "my.h"
#include "struct.h"
#include <stdio.h>
#include <time.h>

void free_func_list(func_t **head)
{
    func_t *current = *head;
    func_t *temp = *head;

    while (current) {
        temp = current;
        current = temp->next;
        free(temp);
        temp = NULL;
    }
}

void free_everything(core_t *core)
{
    player_t *current = core->player_head;
    player_t *temp;

    while (current) {
        temp = current;
        current = current->next;
        if (temp->input)
            fclose(temp->input);
        free(temp);
    }
}
