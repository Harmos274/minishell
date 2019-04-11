/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains the execution list structure
*/

#include "structures/token_list.h"

#ifndef EXEC_LIST_H_
    #define EXEC_LIST_H_
    typedef struct execution_list_s {
        token_list_t *token_list;
        int in;
        int out;
        struct execution_list_s *next;
    } exec_list_t;
#endif /* !EXEC_LIST_H_ */