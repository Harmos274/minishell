/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains functions used by the setenv builtin
*/

#include <malloc.h>
#include "structures/command.h"
#include "functions/env_handling.h"

void move_env_vars(char **env, int pos)
{
    while (env[pos + 1]) {
        env[pos] = env[pos + 1];
        ++pos;
    }
    env[pos] = NULL;
}

char **builtin_unsetenv(char **env, command_t *command, int *status)
{
    int pos = 1;
    int elem;

    while (pos < command->words_nbr) {
        elem = find_env_var(env, command->words[pos]);
        if (elem != -1) {
            free(env[elem]);
            move_env_vars(env, elem);
        }
        ++pos;
    }
    *status = 0;
    return (env);
}