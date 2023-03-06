/*
** EPITECH PROJECT, 2019
** my_functions.h
** File description:
** classic header
*/

#ifndef FCT_H
#define FCT_H
#include "my_structs.h"
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ncurses.h>
#include <stdio.h>

long long find_size_file(char *path);
int read_file(data_t *data);
list_block_t *init_list_block(void);
list_loc_t *init_list_loc(void);
data_t *init_data(char *path);
void find_height(data_t *data);
void find_width(data_t *data);
int find_width_i(data_t *data, int cmp);
void create_save_map(data_t *data);
void create_map2(data_t *data, int x, int y, int i);
void create_map(data_t *data);
void disp_map(data_t *data);
void init(void);
void add_block(data_t *data, long x, long y);
void add_loc(data_t *data, long x, long y);
void fill_struct2(data_t *data, int x, int y);
void fill_struct(data_t *data);
void change_block_coord(data_t *data, int move);
void my_putstr(char *str);
void check_win2(data_t *data, block_t *actual_block, loc_t *actual_loc);
void check_win(data_t *data);
void check_lose1(data_t *data, block_t *actual_block);
void check_lose2(data_t *data, block_t *actual_block);
void check_lose(data_t *data);
void reset_map(data_t *data);
void free_list2(data_t *data, loc_t *actual_loc);
void free_list(data_t *data);
void free_all(data_t *data);
int gests_error(data_t *data);
void re_add_0(data_t *data);
void sokoban_start(data_t *data);
void key_right2(data_t *data);
void key_right(data_t *data);
void key_reset(data_t *data);
void key_left2(data_t *data);
void key_left(data_t *data);
void key_up2(data_t *data);
void key_up(data_t *data);
void key_down2(data_t *data);
void key_down(data_t *data);
int end(data_t *data);
void key(data_t *data);
int sokoban(char *str);
void help(void);


#endif
