/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains functions used by the setenv builtin
*/

#include <unistd.h>
#include <malloc.h>
#include "structures/command.h"
#include "functions/builtin.h"
#include "functions/env_handling.h"
#include "functions/char_toolbox.h"
#include "functions/string_toolbox.h"

static int check_var_name(char const *name)
{
    int size = my_strlen(name);
    int pos = 1;

    if (size < 1 || !is_letter(name[0])) {
        write(1, "setenv: Variable name must begin with a letter.\n", 48);
        return (0);
    }
    while (name[pos] != '\0') {
        if (!(is_alphanumerical(name[pos]) || name[pos] == '_')) {
            write(1, "setenv: Variable name must contain alphanumeric ", 48);
            write(1, "characters.\n", 12);
            return (0);
        }
        ++pos;
    }
    return (1);
}

char **enlarge_env(char **env)
{
    int oldsize = get_env_size(env);
    char **new_env = malloc(sizeof(char *) * (oldsize + 1));
    int pos = 0;

    if (new_env) {
        while (pos < oldsize) {
            new_env[pos] = env[pos];
            ++pos;
        }
        new_env[pos] = NULL;
    }
    free(env);
    return (new_env);
}

char **edit_variable(char **env, int args_nbr, char **args, int *status)
{
    int pos;

    if (check_var_name(args[1])) {
        pos = find_env_var(env, args[1]);
        if (pos == -1) {
            env = enlarge_env(env);
            pos = get_env_size(env) - 1;
        } else {
            free(env[pos]);
        }
        env[pos] = create_variable(args, args_nbr);
        *status = 0;
    }
    else {
        *status = 1;
    }
    return (env);
}

char **builtin_setenv(char **env, command_t *command, int *status)
{

    if (command->words_nbr >= 2 && command->words_nbr <= 3) {
        env = edit_variable(env, command->words_nbr, command->words, status);
    }
    else if (command->words_nbr == 1) {
        env = builtin_env(env, command, status);
    }
    else {
        *status = 1;
        write (1, "setenv: Too many arguments.\n", 28);
    }
    return (env);
}