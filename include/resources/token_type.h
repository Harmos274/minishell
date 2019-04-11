/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains the token type enum
*/

#ifndef TOKEN_TYPE_H_
    #define TOKEN_TYPE_H_
    typedef enum token_type_e {
        WORD = 0,
        PIPE,
        IN_REDIR,
        IN_REDIR_D,
        OUT_REDIR,
        OUT_REDIR_D,
        SEPARATOR
    } token_type_t;
#endif
