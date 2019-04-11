/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains functions used to modify the env variable
*/

#include <malloc.h>
#include "functions/string_toolbox.h"

void free_env(char **env)
{
    int pos = 0;

    if (env) {
        while (env[pos]) {
            free(env[pos]);
            ++pos;
        }
        free(env);
    }
}

int get_env_size(char **env)
{
    int size = 0;

    while (env[size]) {
        ++size;
    }
    ++size;
    return (size);
}

char **envdup(char **env)
{
    char **new_env = malloc(sizeof(char *) * (get_env_size(env)));
    int pos = 0;

    if (new_env) {
        while (env[pos]) {
            new_env[pos] = my_strndup(env[pos], my_strlen(env[pos]));
            ++pos;
        }
        new_env[pos] = NULL;
    }
    return (new_env);
}

int is_same_var(char const *variable, char const *reference)
{
    int pos = 0;

    while (variable[pos] != '\0' && reference[pos] != '\0') {
        if (variable[pos] != reference[pos]) {
            return (0);
        }
        ++pos;
    }
    if (reference[pos] != '=' || variable[pos] != '\0') {
        return (0);
    }
    return (1);
}