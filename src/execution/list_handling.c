/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains execution lists handling functions
*/

#include <malloc.h>
#include "resources/token_type.h"
#include "structures/exec_list.h"
#include "structures/token_list.h"
#include "functions/tokens_handling.h"
#include "functions/exec_list_handling.h"

void destroy_exec_list(exec_list_t *list)
{
    exec_list_t *temp = NULL;

    while (list) {
        temp = list->next;
        destroy_token_list(list->token_list);
        free(list);
        list = temp;
    }
}

static token_list_t *get_next_token(token_list_t *tokens)
{
    token_list_t *temp = NULL;

    while (tokens && tokens->type == SEPARATOR) {
        temp = tokens->next;
        free(tokens);
        tokens = temp;
    }
    return (tokens);
}

static void transfer_tokens(token_list_t *tokens, exec_list_t *list)
{
    token_list_t *temp_token = NULL;

    while (tokens) {
        if (tokens->next && tokens->next->type == SEPARATOR) {
            temp_token = tokens->next->next;
            free(tokens->next);
            tokens->next = NULL;
            list->next = create_exec_list(temp_token);
        }
        tokens = tokens->next;
    }
}

int check_exec_list(exec_list_t *list)
{
    int status = 1;

    while (status && list) {
        status = check_token_list(list->token_list);
        list = list->next;
    }
    return (status);
}

exec_list_t *create_exec_list(token_list_t *tokens)
{
    exec_list_t *list = NULL;

    tokens = get_next_token(tokens);
    if (tokens) {
        list = malloc(sizeof(*list));
    }
    if (list) {
        list->next = NULL;
        list->token_list = tokens;
        transfer_tokens(tokens, list);
    }
    return (list);
}