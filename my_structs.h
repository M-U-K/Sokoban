/*
** EPITECH PROJECT, 2019
** my_structs.h
** File description:
** classic header
*/

#ifndef STR_H
#define STR_H

typedef struct block_s
{
    struct block_s *next;
    struct block_s *prev;
    long x_coord;
    long y_coord;
    int can_move;
    int lose;
}block_t;

typedef struct list_block_s
{
    int nbr;
    struct block_s *first;
}list_block_t;

typedef struct loc_s
{
    struct loc_s *next;
    struct loc_s *prev;
    long x_coord;
    long y_coord;
}loc_t;

typedef struct list_loc_s
{
    int nbr;
    struct loc_s *first;
}list_loc_t;


typedef struct data_s
{
    int win;
    int cmp_win;
    int cmp_lose;
    long width;
    long height;
    long x_player;
    long y_player;
    long save_x_player;
    long save_y_player;
    long long size_file;
    char *buff;
    char *path;
    char **map;
    char **save_map;
    int end;
    int key;
    struct list_loc_s *list_loc;
    struct list_block_s *list_block;
}data_t;

#endif
