/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** kill_player
*/

#include "my.h"
#include "struct.h"
#include <stdio.h>

void free_all_heads(finger_t *finger)
{
    finger_t *current = finger;
    finger_t *temp;

    while (current) {
        temp = current;
        current = current->next;
        if (temp->func) {
            free(temp->func);
        }
        free(temp);
    }
}

/*
** this func should only be called if there is a valid reason to kill a player
** reasons -> no heads, run out of live counter
** it will automatically move on to next pointer for the user
*/
void kill_player(core_t *core, player_t **player)
{
    player_t *current = core->player_head;
    player_t *temp = *player;

    if (!current) {
        core->error_occured = true;
        return;
    }
    if (temp->fing_head)
        free_all_heads(temp->fing_head);
    if (core->player_head == temp) {
        core->player_head = temp->next;
    } else {
        while (current && current->next != temp)
            current = current->next;
        current->next = temp->next;
    }
    if (temp->input)
        fclose(temp->input);
    *player = temp->next;
    free(temp);
}
