/*
** EPITECH PROJECT, 2019
** key2.c
** File description:
** key2.c
*/

#include "my_functions.h"

void key_left(data_t *data)
{
    if (data->key == KEY_LEFT) {
        if (data->map[data->y_player][data->x_player-1] == 'X')
            key_left2(data);
        else if (data->map[data->y_player][data->x_player-1] \
== ' ' || data->map[data->y_player][data->x_player-1] == 'O'){
            mvprintw(data->y_player, data->x_player, " ");
            data->x_player --;
        }
    }
}

void key_up2(data_t *data)
{
    if ((data->map[data->y_player-2][data->x_player] \
== ' ' || data->map[data->y_player-2][data->x_player] == 'O')){
        change_block_coord(data, 4);
        data->map[data->y_player-2][data->x_player] = 'X';
        mvprintw(data->y_player-2, data->x_player, "X");
        data->map[data->y_player-1][data->x_player] = ' ';
        data->map[data->y_player][data->x_player] = ' ';
        mvprintw(data->y_player, data->x_player, " ");
        data->y_player --;
    }
}

void key_up(data_t *data)
{
    if (data->key == KEY_UP) {
        if (data->map[data->y_player-1][data->x_player] == 'X')
            key_up2(data);
        else if (data->map[data->y_player-1][data->x_player] \
== ' ' || data->map[data->y_player-1][data->x_player] == 'O'){
            mvprintw(data->y_player, data->x_player, " ");
            data->y_player --;
        }
    }
}

void key_down2(data_t *data)
{
    if ((data->map[data->y_player+2][data->x_player] \
== ' ' || data->map[data->y_player+2][data->x_player] == 'O')){
        change_block_coord(data, 3);
        data->map[data->y_player+2][data->x_player] = 'X';
        mvprintw(data->y_player+2, data->x_player, "X");
        data->map[data->y_player+1][data->x_player] = ' ';
        data->map[data->y_player][data->x_player] = ' ';
        mvprintw(data->y_player, data->x_player, " ");
        data->y_player ++;
    }
}

void key_down(data_t *data)
{
    if (data->key == KEY_DOWN) {
        if (data->map[data->y_player+1][data->x_player] == 'X')
            key_down2(data);
        else if (data->map[data->y_player+1][data->x_player] \
== ' ' || data->map[data->y_player+1][data->x_player] == 'O'){
            mvprintw(data->y_player, data->x_player, " ");
            data->y_player ++;
        }
    }
}
