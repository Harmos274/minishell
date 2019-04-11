/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains the token list struct
*/

#include "resources/token_type.h"

#ifndef TOKEN_LIST_H_
    #define TOKEN_LIST_H_
    typedef struct token_list_s {
        char *word;
        token_type_t type;
        struct token_list_s *next;
    } token_list_t;
#endif
