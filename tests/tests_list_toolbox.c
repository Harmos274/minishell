/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains token list related functions' unit tests
*/

#include <malloc.h>
#include <criterion/criterion.h>
#include "structures/token_list.h"
#include "functions/tokens_handling.h"

Test(add_token_to_list, with_empty_list)
{
    token_list_t *elem = malloc(sizeof(*elem));
    token_list_t *list = NULL;

    if (elem) {
        elem->type = PIPE;
        elem->next = NULL;
        add_token_to_list(&list, elem);
        cr_assert(list->type = PIPE);
        free(list);
    }
}

Test(add_token_to_list, with_existing_list)
{
    token_list_t *list = malloc(sizeof(*list));
    token_list_t *elem = malloc(sizeof(*elem));

    cr_assert(list && elem);
    list->type = PIPE;
    list->next = NULL;
    elem->type = WORD;
    elem->next = NULL;
    add_token_to_list(&list, elem);
    cr_assert(list->type == PIPE && list->next->type == WORD);
    free(list);
    free(elem);
}