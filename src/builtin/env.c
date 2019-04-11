/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains functions used by the env builtin
*/

#include <unistd.h>
#include "structures/command.h"
#include "functions/string_toolbox.h"
#include "functions/env_handling.h"

char **builtin_env(char **env, command_t *command, int *status)
{
    int pos = 0;

    if (command->words_nbr == 1) {
        while (env[pos]) {
            write(command->fd_out, env[pos], my_strlen(env[pos]));
            write(command->fd_out, "\n", 1);
            ++pos;
        }
    }
    else {
        write(2, "The env builtin does not support argument\n", 42);
    }
    *status = 0;
    return (env);
}