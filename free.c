/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** free.c
*/

#include "my_functions.h"

void free_list2(data_t *data, loc_t *actual_loc)
{
    while (actual_loc->next) {
        actual_loc->next->prev = actual_loc;
        actual_loc = actual_loc->next;
    }
    actual_loc = data->list_loc->first;
    while (actual_loc->next) {
        actual_loc = actual_loc->next;
        free(actual_loc->prev);
    }
}

void free_list(data_t *data)
{
    block_t *actual_block = data->list_block->first;
    loc_t *actual_loc = data->list_loc->first;

    free_list2(data, actual_loc);
    while (actual_block->next) {
        actual_block->next->prev = actual_block;
        actual_block = actual_block->next;
    }
    actual_block = data->list_block->first;
    while (actual_block->next) {
        actual_block = actual_block->next;
        free(actual_block->prev);
    }
    data->list_block->first = NULL;
    data->list_loc->first = NULL;
    data->list_block->nbr = 0;
    data->list_loc->nbr = 0;
}

void free_all(data_t *data)
{
    for (int i = 0; i != data->height; i++) {
        free(data->map[i]);
        free(data->save_map[i]);
    }
}

int gests_error(data_t *data)
{
    for (int i = 0; data->buff[i] != '\0'; i ++) {
        if (data->buff[i] != '#' && data->buff[i] != '\n' \
&& data->buff[i] != 'X' && data->buff[i] != 'O' && data->b\
uff[i] != 'P' && data->buff[i] != ' ')
            return (1);
    }
    return (0);
}

void re_add_0(data_t *data)
{
    loc_t *actual_loc = data->list_loc->first;

    while (actual_loc->next) {
        if (data->map[actual_loc->y_coord][actual_loc->x_coord] == ' ')
            data->map[actual_loc->y_coord][actual_loc->x_coord] = 'O';
        actual_loc = actual_loc->next;
    }
}
