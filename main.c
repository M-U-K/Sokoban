/*
** EPITECH PROJECT, 2019
** main for sokoban
** File description:
** main.c
*/

#include "my_functions.h"

int end(data_t *data)
{
    if (data->win == 1) {
        free_all(data);
        return (0);
    }
    if (data->win == 2) {
        free_all(data);
        return (1);
    }
    return (84);
}

void key(data_t *data)
{
    key_reset(data);
    key_right(data);
    key_left(data);
    key_up(data);
    key_down(data);
}

int sokoban(char *str)
{
    data_t *data = init_data(str);

    if (read_file(data))
        return (84);
    if (gests_error(data))
        return (84);
    sokoban_start(data);
    while (data->end == 0) {
        mvprintw(data->y_player, data->x_player, "P");
        data->key = getch();
        key(data);
        re_add_0(data);
        disp_map(data);
        check_win(data);
        check_lose(data);
        refresh();
    }
    endwin();
    return (end(data));
    return (84);
}

void help(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPT\
ION\n     map   file representing the warehouse map, \
containing '#' for walls,\n           'P' for the pla\
yer, 'X' for boxes and 'O' for storage locations.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help();
    if (ac == 2 && av[1][0] != '-' && av[1][1] != 'h')
        return (sokoban(av[1]));
    return (84);
}
