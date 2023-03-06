/*
** EPITECH PROJECT, 2019
** key.c
** File description:
** key.c
*/

#include "my_functions.h"

void sokoban_start(data_t *data)
{
    init();
    create_map(data);
    create_save_map(data);
    fill_struct(data);
    noecho();
    cbreak();
    curs_set(FALSE);
    disp_map(data);
}

void key_right2(data_t *data)
{
    if ((data->map[data->y_player][data->x_player+2] \
== ' ' || data->map[data->y_player][data->x_player+2] == 'O')){
        change_block_coord(data, 1);
        data->map[data->y_player][data->x_player+2] = 'X';
        mvprintw(data->y_player, data->x_player+2, "X");
        data->map[data->y_player][data->x_player+1] = ' ';
        data->map[data->y_player][data->x_player] = ' ';
        mvprintw(data->y_player, data->x_player, " ");
        data->x_player ++;
    }
}

void key_right(data_t *data)
{
    if (data->key == KEY_RIGHT){
	if (data->map[data->y_player][data->x_player+1] == 'X')
            key_right2(data);
        else if (data->map[data->y_player][data->x_player+1] \
== ' ' || data->map[data->y_player][data->x_player+1] == 'O'){
            mvprintw(data->y_player, data->x_player, " ");
            data->x_player ++;
        }
    }
}

void key_reset(data_t *data)
{
    if (data->key == ' '){
        reset_map(data);
        free_list(data);
        data->list_block = init_list_block();
        data->list_loc = init_list_loc();
        fill_struct(data);
    }
}

void key_left2(data_t *data)
{
    if ((data->map[data->y_player][data->x_player-2] \
== ' ' || data->map[data->y_player][data->x_player-2] == 'O')){
        change_block_coord(data, 2);
        data->map[data->y_player][data->x_player-2] = 'X';
        mvprintw(data->y_player, data->x_player-2, "X");
        data->map[data->y_player][data->x_player-1] = ' ';
        data->map[data->y_player][data->x_player] = ' ';
        mvprintw(data->y_player, data->x_player, " ");
        data->x_player --;
    }
}
