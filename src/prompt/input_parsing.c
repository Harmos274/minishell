/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains user input parsing
*/

#include <malloc.h>
#include "structures/token_list.h"
#include "resources/token_creators.h"
#include "functions/tokens_handling.h"

static int get_next_symbol(char *str, int *pos, token_list_t **list)
{
    int status = 1;
    int token = 0;

    while (str[*pos] != '\0' && (str[*pos] == ' ' || str[*pos] == '\t')) {
        *pos += 1;
    }
    if (str[*pos] != '\0') {
        while (TOKENS_CHRS[token] != '\0' && TOKENS_CHRS[token] != str[*pos]) {
            ++token;
        }
        status = add_token_to_list(list, TOKENS_FUNCS[token](str, pos));
    }
    return (status);
}

token_list_t *parse_line(char *str)
{
    token_list_t *list = NULL;
    int status = 1;
    int pos = 0;

    if (str) {
        while (status && str[pos] != '\0') {
            status = get_next_symbol(str, &pos, &list);
        }
    }
    return (list);
}