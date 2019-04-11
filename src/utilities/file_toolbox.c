/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains functions used to handle files
*/

#include <unistd.h>
#include <malloc.h>
#include "functions/string_toolbox.h"

char *path_concat(char const *path, char const *filename)
{
    int size = my_strlen(path);
    int written;
    char *result;

    if (path[size - 1] != '/') {
        ++size;
    }
    size += my_strlen(filename);
    result = malloc(sizeof(char) * (size + 1));
    if (result) {
        written = my_strcpy(path, result);
        if (result[written - 1] != '/') {
            result[written] = '/';
            ++written;
        }
        my_strcpy(filename, &result[written]);
        result[size] = '\0';
    }
    return (result);
}

int is_file_executable(char const *path)
{
    return (access(path, X_OK) + 1);
}