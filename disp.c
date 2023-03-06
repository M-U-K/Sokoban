/*
** EPITECH PROJECT, 2019
** disp.c
** File description:
** disp.c
*/

#include "my_functions.h"

void create_map(data_t *data)
{
    int x = 0;
    int y = 0;

    find_width(data);
    find_height(data);
    data->map = malloc(sizeof(char *) * (data->height));
    for (int i = 0; i != data->height; i++)
        data->map[i] = malloc(sizeof(char) * (find_width_i(data, i)) + 1);
    for (int i = 0; data->buff[i+1] != '\0';i++, y++) {
        if (data->buff[i] == '\n') {
            data->map[x][y] = '\0';
            y = 0;
            x++;
            i++;
        }
        create_map2(data, x, y, i);
        if (data->buff[i] != 'P')
            data->map[x][y] = data->buff[i];
    }
    data->map[x][y] = '\0';
}

void disp_map(data_t *data)
{
    for (int i = 0; i != data->height; i++)
        mvprintw(i, 0, data->map[i]);
}

void init(void)
{
    initscr();
    keypad(stdscr, TRUE);
    attron(A_NORMAL);
}

void add_block(data_t *data, long x, long y)
{
    block_t *new = malloc(sizeof(block_t));

    new->x_coord = x;
    new->y_coord = y;
    new->can_move = 0;
    new->lose = 0;
    new->next = data->list_block->first;
    data->list_block->nbr++;
    data->list_block->first = new;
}

void add_loc(data_t *data, long x, long y)
{
    loc_t *new = malloc(sizeof(loc_t));

    new->x_coord = x;
    new->y_coord = y;
    new->next = data->list_loc->first;
    data->list_loc->nbr++;
    data->list_loc->first = new;
}
