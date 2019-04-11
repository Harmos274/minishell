/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains token creation related functions' prototypes
*/

#include "structures/token_list.h"

#ifndef TOKEN_CREATION_H_
    #define TOKEN_CREATION_H_
    token_list_t *create_pipe(char *str, int *pos);
    token_list_t *create_word(char *str, int *pos);
    token_list_t *create_redir_in(char *str, int *pos);
    token_list_t *create_redir_out(char *str, int *pos);
    token_list_t *create_separator(char *str, int *pos);
#endif /* !TOKEN_CREATION_H_ */