/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains word token related functions
*/

#include <malloc.h>
#include "functions/str_display.h"
#include "functions/string_toolbox.h"

static int is_end(char chr)
{
    int is_end = 0;

    if (chr == ' ' || chr == '\t' || chr == '<' || chr == '>' || chr == '|') {
        is_end = 1;
    }
    else if (chr == ';' || chr == '\0') {
        is_end = 1;
    }
    return (is_end);
}

static int get_word_size(char *str, int pos)
{
    int to_remove = 0;
    int new_pos = pos;

    while (new_pos != -1 && !is_end(str[new_pos])) {
        if (str[new_pos] == '\'' || str[new_pos] == '\"') {
            new_pos = get_next_occurence(str, new_pos + 1, str[new_pos], 1);
            to_remove += 2;
        }
        if (new_pos != -1 && str[new_pos] != '\0') {
            ++new_pos;
        }
    }
    if (new_pos != -1) {
        new_pos -= pos + to_remove;
    }
    return (new_pos);
}

static void copy_quote_content(char *str, char *word, int *pos, int *word_pos)
{
    char quote = str[*pos];

    *pos += 1;
    while (str[*pos] != quote && str[*pos] != '\0') {
        word[*word_pos] = str[*pos];
        *word_pos += 1;
        *pos += 1;
    }
}

static int copy_word(char *str, char *word, int *pos, int size)
{
    int word_pos = 0;

    while (word_pos < size) {
        if (str[*pos] == '\'' || str[*pos] == '\"') {
            copy_quote_content(str, word, pos, &word_pos);
        }
        else {
            word[word_pos] = str[*pos];
            ++word_pos;
        }
        *pos += 1;
    }
    return (word_pos);
}

char *get_word(char *str, int *pos)
{
    int word_pos = 0;
    char *word = NULL;
    int size = get_word_size(str, *pos);

    if (size > 0) {
        word = malloc(sizeof(char) * (size + 1));
    }
    else {
        *pos = -1;
    }
    if (word) {
        word_pos = copy_word(str, word, pos, size);
        word[word_pos] = '\0';
    }
    return (word);
}