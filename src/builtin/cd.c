/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains functions used by the cd builtin
*/

#include <malloc.h>
#include <unistd.h>
#include "structures/command.h"
#include "functions/builtin.h"
#include "functions/str_display.h"
#include "functions/env_handling.h"
#include "functions/string_toolbox.h"

static char **set_pwd_var(char **env, char *path, int *status)
{
    char *oldcwd_args[] = {"setenv", "OLDPWD", get_var_value(env, "PWD")};
    char *cwd_args[] = {"setenv", "PWD", path};

    env = edit_variable(env, 3, oldcwd_args, status);
    env = edit_variable(env, 3, cwd_args, status);
    return (env);
}

static char **change_cwd(char **env, char *path, int *status)
{
    char *cwd = NULL;

    if (my_strlen(path) == 1 && path[0] == '-') {
        path = get_var_value(env, "OLDPWD");
    }
    *status = chdir(path);
    if (!*status) {
        cwd = getcwd(cwd, 0);
        env = set_pwd_var(env, cwd, status);
        free(cwd);
    }
    else {
        my_perror(path);
        *status = 1;
    }
    return (env);
}

char **builtin_cd(char **env, command_t *command, int *status)
{
    char *path = NULL;

    if (command->words_nbr <= 2) {
        if (command->words_nbr == 1 || my_strstr(command->words[0], "~")) {
            path = get_var_value(env, "HOME");
        }
        else if (command->words_nbr == 2) {
            path = command->words[1];
        }
        if (path) {
            env = change_cwd(env, path, status);
        }
    }
    else {
        write(2, "cd: Too many arguments\n", 23);
        *status = 1;
    }
    return (env);
}