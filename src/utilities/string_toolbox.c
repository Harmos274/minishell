/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** Contains strings related functions
*/

#include <unistd.h>
#include <malloc.h>
#include "functions/str_display.h"

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        ++len;
    }
    return (len);
}

int my_strcpy(char const *source, char *dest)
{
    int pos = 0;

    while (source[pos] != '\0') {
        dest[pos] = source[pos];
        ++pos;
    }
    return (pos);
}

int get_next_occurence(char const *str, int pos, char const to_find, int strict)
{
    while (str[pos] != to_find && str[pos] != '\0') {
        ++pos;
    }
    if (strict && str[pos] == '\0') {
        pos = -1;
        display_unmatched(to_find, 2);
    }
    return (pos);
}

char *my_strndup(char const *str, int const to_copy)
{
    int pos = 0;
    char *result = malloc(sizeof(char) * (to_copy + 1));

    if (result) {
        while (pos < to_copy) {
            result[pos] = str[pos];
            ++pos;
        }
        result[pos] = '\0';
    }
    return (result);
}

int my_strstr(char const *str1, char const *str2)
{
    int pos = 0;

    while (str1[pos] != '\0' && str2[pos] != '\0') {
        if (str1[pos] != str2[pos]) {
            return (0);
        }
        ++pos;
    }
    if (str2[pos] != str1[pos]) {
        return (0);
    }
    return (1);
}