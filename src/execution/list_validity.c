/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains functions used to test an exec list's validity
*/

#include <stddef.h>
#include "structures/exec_list.h"
#include "structures/token_list.h"
#include "functions/str_display.h"

static int get_pipes_nbr(token_list_t *list)
{
    int pipes = 0;

    while (list) {
        if (list->type == PIPE) {
            ++pipes;
        }
        list = list->next;
    }
    return (pipes);
}

static int check_redirs_nbr(token_list_t *list)
{
    int out_redir = 0;
    int in_redir = 0;
    int status = 1;

    while (status && list) {
        if (list->type == IN_REDIR || list->type == IN_REDIR_D)
            ++in_redir;
        else if (list->type == OUT_REDIR || list->type == OUT_REDIR_D)
            ++out_redir;
        list = list->next;
    }
    if (out_redir > 1) {
        status = 0;
        my_putstr("Ambiguous output redirect.\n", 2);
    }
    else if (in_redir > 1) {
        status = 0;
        my_putstr("Ambiguous input redirect.\n", 2);
    }
    return (status);
}

static int check_redirs_pos(token_list_t *list)
{
    int pipes_nbr = get_pipes_nbr(list);
    int status = 1;
    int pipes = 0;

    while (status && list) {
        if (list->type == PIPE) {
            ++pipes;
        }
        if ((list->type == IN_REDIR || list->type == IN_REDIR_D) && pipes) {
            my_putstr("Ambiguous input redirect.\n", 2);
            status = 0;
        }
        else if ((list->type == OUT_REDIR || list->type == OUT_REDIR_D) &&
        pipes != pipes_nbr) {
            my_putstr("Ambiguous output redirect.\n", 2);
            status = 0;
        }
        list = list->next;
    }
    return (status);
}

static int check_commands(token_list_t *list)
{
    int has_word = 0;
    int status = 1;

    while (status && list) {
        if (list->type == WORD && !has_word)
            has_word = 1;
        if (list->type == PIPE && has_word)
            has_word = 0;
        else if (list->type == PIPE && !has_word)
            status = 0;
        list = list->next;
    }
    if (!has_word) {
        my_putstr("Invalid null command.\n", 2);
        status = 0;
    }
    return (status);
}

int check_token_list(token_list_t *list)
{
    int status = 1;

    status = check_redirs_pos(list);
    if (status) {
        status = check_redirs_nbr(list);
        if (status) {
            status = check_commands(list);
        }
    }
    return (status);
}