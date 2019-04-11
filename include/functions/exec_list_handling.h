/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains exec list handling related functions' prototypes
*/

#include "structures/token_list.h"
#include "structures/exec_list.h"

#ifndef EXEC_LIST_HANDLING_H_
    #define EXEC_LIST_HANDLING_H_
    exec_list_t *create_exec_list(token_list_t *tokens);
    void destroy_exec_list(exec_list_t *list);
    int check_token_list(token_list_t *list);
    int check_exec_list(exec_list_t *list);
#endif /* !EXEC_LIST_HANDLING_H_ */