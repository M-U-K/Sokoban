/*
** EPITECH PROJECT, 2019
** data.c
** File description:
** data for sokoban
*/

#include "my_functions.h"

void find_height(data_t *data)
{
    int i = 0;
    int cmp = 0;

    for (; data->buff[i] != '\0'; i ++) {
        if (data->buff[i] == '\n')
            cmp ++;
    }
    data->height = cmp;
}

void find_width(data_t *data)
{
    int i = 0;

    for (; data->buff[i] != '\n'; i ++);
    data->width = i+1;
}

int find_width_i(data_t *data, int cmp)
{
    int i = 0;
    int tmp = 0;

    for (int j = 0; j != cmp; j++) {
        for (; data->buff[i] != '\n'; i ++);
        i++;
    }
    tmp = i;
    for (; data->buff[i] != '\n'; i++);
    i = i - tmp;
    return (i);
}

void create_save_map(data_t *data)
{
    int x = 0;
    int y = 0;

    data->save_map = malloc(sizeof(char *) * (data->height));
    for (int i = 0; i != data->height; i++)
        data->save_map[i] = malloc(sizeof(char) * (find_width_i(data, i)) + 1);

    for (int x = 0; x != data->height; x++) {
        for (int y = 0; y != find_width_i(data, x); y ++) {
            data->save_map[x][y] = data->map[x][y];
        }
    }
    data->save_map[x][y] = '\0';
}

void create_map2(data_t *data, int x, int y, int i)
{
    if (data->buff[i] == 'P') {
        data->map[x][y] = ' ';
        data->x_player = y;
        data->y_player = x;
        data->save_x_player = y;
        data->save_y_player = x;
    }
}
