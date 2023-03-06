/*
** EPITECH PROJECT, 2019
** tools
** File description:
** tools.c
*/

#include "my_functions.h"

long long find_size_file(char *path)
{
    struct stat inf_text;

    if (stat(path, &inf_text) == - 1){}
    return (inf_text.st_size);
}

int read_file(data_t *data)
{
    int fd = open(data->path, O_RDONLY);
    int offset = 0;
    int len;

    while ((len = read(fd, data->buff + offset, data->size_file - offset)) > 0)
        offset = offset + len;
    data->buff[offset] = '\0';
    if (len < 0)
        return (1);
    return (0);
}

list_block_t *init_list_block(void)
{
    list_block_t *new_list = malloc(sizeof(list_block_t));
    block_t *new_block = malloc(sizeof(block_t));

    new_block->next = NULL;
    new_list->first = new_block;
    new_list->nbr = 0;
    return (new_list);
}

list_loc_t *init_list_loc(void)
{
    list_loc_t *new_list = malloc(sizeof(list_loc_t));
    loc_t *new_loc = malloc(sizeof(loc_t));

    new_loc->next = NULL;
    new_list->first = new_loc;
    new_list->nbr = 0;
    return (new_list);
}

data_t *init_data(char *path)
{
    data_t *new = malloc(sizeof(data_t));

    new->size_file = find_size_file(path);
    new->path = path;
    new->buff = malloc(sizeof(char) * (new->size_file + 1));
    new->list_block = init_list_block();
    new->list_loc = init_list_loc();
    new->end = 0;
    return (new);
}
