/*
** EPITECH PROJECT, 2019
** check.c
** File description:
** check.c
*/

#include "my_functions.h"

void check_win(data_t *data)
{
    block_t *actual_block = data->list_block->first;
    loc_t *actual_loc = data->list_loc->first;

    data->cmp_win = 0;
    while (actual_block->next) {
        actual_loc = data->list_loc->first;
        while (actual_loc->next) {
            check_win2(data, actual_block, actual_loc);
            actual_loc = actual_loc->next;
        }
        actual_block = actual_block->next;
    }
    if (data->cmp_win == data->list_loc->nbr) {
        data->end = 1;
        data->win = 1;
    }
}

void check_lose1(data_t *data, block_t *actual_block)
{
    if ((data->map[actual_block->y_coord+1][actual_block->\
x_coord] == '#' || data->map[actual_block->y_coord+1][actu\
al_block->x_coord] == 'X') && (data->map[actual_block->y_c\
oord][actual_block->x_coord-1] == '#' || data->map[actual_\
block->y_coord][actual_block->x_coord-1] == 'X')) {
        actual_block->lose = 1;
        data->cmp_lose++;
    }
    if ((data->map[actual_block->y_coord+1][actual_block->\
x_coord] == '#' || data->map[actual_block->y_coord+1][actu\
al_block->x_coord] == 'X') && (data->map[actual_block->y_c\
oord][actual_block->x_coord+1] == '#' || data->map[actual_\
block->y_coord][actual_block->x_coord+1] == 'X')) {
        actual_block->lose = 1;
        data->cmp_lose++;
    }
}

void check_lose2(data_t *data, block_t *actual_block)
{
    if ((data->map[actual_block->y_coord-1][actual_block->\
x_coord] == '#' || data->map[actual_block->y_coord][actual\
_block->x_coord+1] == 'X') && (data->map[actual_block->y_c\
oord][actual_block->x_coord-1] == '#' || data->map[actual_\
block->y_coord][actual_block->x_coord-1] == 'X')) {
        actual_block->lose = 1;
        data->cmp_lose++;
    }
    if ((data->map[actual_block->y_coord-1][actual_block->\
x_coord] == '#' || data->map[actual_block->y_coord][actual\
_block->x_coord-1] == 'X') && (data->map[actual_block->y_c\
oord][actual_block->x_coord+1] == '#' || data->map[actual_\
block->y_coord][actual_block->x_coord+1] == 'X')) {
        actual_block->lose = 1;
        data->cmp_lose++;
    }
}

void check_lose(data_t *data)
{
    block_t *actual_block = data->list_block->first;

    data->cmp_lose = 0;
    while (actual_block->next) {
        check_lose1(data, actual_block);
        check_lose2(data, actual_block);
        actual_block = actual_block->next;
    }
    if (data->cmp_lose >= data->list_block->nbr && data->end != 1) {
        data->end = 1;
        data->win = 2;
    }
}

void reset_map(data_t *data)
{
    int x = 0;
    int y = 0;

    for (int x = 0; x != data->height; x++) {
        for (int y = 0; y != find_width_i(data, x); y ++) {
            data->map[x][y] = data->save_map[x][y];
        }
    }
    data->map[x][y] = '\0';
    data->y_player = data->save_y_player;
    data->x_player = data->save_x_player;
}
