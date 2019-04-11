/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains token creation functions
*/

#include <malloc.h>
#include "structures/token_list.h"
#include "functions/str_display.h"
#include "functions/tokens_handling.h"

token_list_t *create_word(char *str, int *pos)
{
    token_list_t *word = malloc(sizeof(*word));

    if (word) {
        word->type = WORD;
        word->next = NULL;
        word->word = get_word(str, pos);
        if (!word->word) {
            free(word);
            word = NULL;
        }
    }
    return (word);
}

token_list_t *create_redir_in(char *str, int *pos)
{
    token_list_t *redir = malloc(sizeof(*redir));

    if (redir) {
        redir->next = NULL;
        redir->type = IN_REDIR;
        *pos += 1;
        if (str[*pos] == '<') {
            ++redir->type;
            *pos += 1;
        }
        while (str[*pos] == ' ' || str[*pos] == '\t')
            *pos += 1;
        redir->word = get_word(str, pos);
        if (!redir->word) {
            my_putstr("Missing name for redirect.\n", 2);
            free(redir);
            redir = NULL;
        }
    }
    return (redir);
}

token_list_t *create_redir_out(char *str, int *pos)
{
    token_list_t *redir = malloc(sizeof(*redir));

    if (redir) {
        redir->next = NULL;
        redir->type = OUT_REDIR;
        *pos += 1;
        if (str[*pos] == '>') {
            ++redir->type;
            *pos += 1;
        }
        while (str[*pos] == ' ' || str[*pos] == '\t')
            *pos += 1;
        redir->word = get_word(str, pos);
        if (!redir->word) {
            my_putstr("Missing name for redirect.\n", 2);
            free(redir);
            redir = NULL;
        }
    }
    return (redir);
}

token_list_t *create_pipe(char *str, int *pos)
{
    token_list_t *pipe = malloc(sizeof(*pipe));

    if (pipe) {
        pipe->word = NULL;
        pipe->next = NULL;
        pipe->type = PIPE;
    }
    if (str[*pos] == '|') {
        *pos += 1;
    }
    return (pipe);
}

token_list_t *create_separator(char *str, int *pos)
{
    token_list_t *separator = malloc(sizeof(*separator));

    if (separator) {
        separator->word = NULL;
        separator->next = NULL;
        separator->type = SEPARATOR;
    }
    while (str[*pos] == ';') {
        *pos += 1;
    }
    return (separator);
}