/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** map.c
*/

#include "my_functions.h"

void fill_struct2(data_t *data, int x, int y)
{
    if (data->map[y][x] == 'O')
        add_loc(data, x, y);
    if (data->map[y][x] == 'X')
        add_block(data, x, y);
}

void fill_struct(data_t *data)
{
    for (int y = 0; y !=data->height; y++) {
        for (int x = 0; x != data->width; x++) {
            fill_struct2(data, x, y);
        }
    }
}

void change_block_coord(data_t *data, int move)
{
    block_t *actual = data->list_block->first;

    while (actual->next) {
        if (actual->y_coord == data->y_player && \
actual->x_coord == data->x_player+1 && move == 1)
            actual->x_coord +=1;
        if (actual->y_coord == data->y_player && \
actual->x_coord == data->x_player-1 && move == 2)
            actual->x_coord -=1;
        if (actual->y_coord == data->y_player+1 && \
actual->x_coord == data->x_player && move == 3)
            actual->y_coord +=1;
        if (actual->y_coord == data->y_player-1 && \
actual->x_coord == data->x_player && move == 4)
            actual->y_coord -=1;
        actual = actual->next;
    }
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i ++)
        write(1, &str[i], 1);
}

void check_win2(data_t *data, block_t *actual_block, loc_t *actual_loc)
{
    if (actual_block->y_coord == actual_loc->y_coord \
&& actual_block->x_coord == actual_loc->x_coord) {
        data->cmp_win++;
    }
}
