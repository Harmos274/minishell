/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains token_creation functions array
*/

#include "structures/token_list.h"
#include "functions/token_creation.h"

#ifndef TOKEN_CREATORS_H_
    #define TOKEN_CREATORS_H_
    char const TOKENS_CHRS[] = {
        ';',
        '<',
        '>',
        '|',
        '\0'
    };
    token_list_t *(* const TOKENS_FUNCS[])(char *str, int *pos) = {
        &create_separator,
        &create_redir_in,
        &create_redir_out,
        &create_pipe,
        &create_word
    };
#endif /* !TOKEN_CREATORS_H_ */