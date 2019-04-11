/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains functions used to manipulate the PATH variable
*/

#include <unistd.h>
#include <malloc.h>
#include "functions/file_toolbox.h"
#include "functions/string_toolbox.h"

void display_not_found(char const *binary)
{
    write(2, binary, my_strlen(binary));
    write(2, ": Command not found.\n", 21);
}

static char *path_var_ndup(char *path_var, int path_pos, int to_copy)
{
    char *dest = malloc(sizeof(char) * (to_copy + 1));
    int dest_pos = 0;

    if (dest) {
        while (dest_pos < to_copy) {
            dest[dest_pos] = path_var[path_pos];
            ++dest_pos;
            ++path_pos;
        }
    }
    dest[dest_pos] = '\0';
    return (dest);
}

static char *try_next_path(char *binary, char *path_var, int pos, int separator)
{
    char *temp_path = path_var_ndup(path_var, pos, separator - pos);
    char *result = NULL;

    if (temp_path) {
        result = path_concat(temp_path, binary);
        free(temp_path);
    }
    return (result);
}

char *search_in_path(char *binary, char *path_var)
{
    int next_separator = get_next_occurence(path_var, 0, ':', 0);
    char *result;
    int pos = 0;

    while (path_var[pos] != '\0') {
        next_separator = get_next_occurence(path_var, pos, ':', 0);
        result = try_next_path(binary, path_var, pos, next_separator);
        if (result && is_file_executable(result)) {
            return (result);
        }
        else if (result) {
            free(result);
        }
        pos = next_separator;
        if (path_var[pos] != '\0') {
            ++pos;
        }
    }
    return (NULL);
}