/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains tokens related functions' prototypes
*/

#include "structures/token_list.h"

#ifndef TOKENS_HANDLING_H_
    #define TOKENS_HANDLING_H_
    char *get_word(char *str, int *pos);
    void destroy_token_list(token_list_t *list);
    int add_token_to_list(token_list_t **list, token_list_t *token);
#endif /* !TOKENS_HANDLING_H_ */