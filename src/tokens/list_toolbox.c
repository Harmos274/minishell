/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains token list related functions
*/

#include <malloc.h>
#include "structures/token_list.h"

void destroy_token_list(token_list_t *list)
{
    token_list_t *next = NULL;

    while (list) {
        next = list->next;
        free(list);
        list = next;
    }
}

int add_token_to_list(token_list_t **list, token_list_t *token)
{
    token_list_t *tokens = *list;

    if (!token) {
        destroy_token_list(*list);
        *list = NULL;
        return (0);
    }
    if (tokens) {
        while (tokens->next) {
            tokens = tokens->next;
        }
        tokens->next = token;
    }
    else {
        *list = token;
    }
    return (1);
}