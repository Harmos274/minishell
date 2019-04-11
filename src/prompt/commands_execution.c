/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains functions used to run commands entered by the user
*/

#include <wait.h>
#include <unistd.h>
#include <malloc.h>
#include "structures/command.h"
#include "functions/str_display.h"
#include "functions/env_handling.h"
#include "functions/string_toolbox.h"
#include "resources/builtins_functions.h"

char *get_correct_path(char *binary, char *path_var)
{
    int binary_len = my_strlen(binary);
    char *correct_path = NULL;

    if (binary_len >= 1 && binary[0] == '/') {
        correct_path = my_strndup(binary, binary_len);
    }
    else if (binary_len >= 2 && binary[0] == '.' && binary[1] == '/') {
        correct_path = my_strndup(binary, binary_len);
    }
    else {
        if (path_var) {
            correct_path = search_in_path(binary, path_var);
        }
    }
    return (correct_path);
}

static int dup_and_exec(char **env, command_t const *cmd, char *path)
{
    int status = 1;

    if (cmd->fd_in >= 0) {
        status = dup2(cmd->fd_in, 0);
    }
    if (status != -1 && cmd->fd_out >= 0) {
        status = dup2(cmd->fd_out, 1);
    }
    if (status != -1) {
        status = execve(path, cmd->words, env);
    }
    free(path);
    return (status);
}

static int exec_binary(char **env, command_t *cmd, int wait)
{
    int status = 1;
    int pid = 0;

    if (cmd->path) {
        pid = fork();
    }
    if (pid) {
        if (wait) {
            waitpid(pid, &status, 0);
            display_signal(status);
        }
    }
    else if (cmd->path && dup_and_exec(env, cmd, cmd->path) == -1)
        builtin_exit(env, cmd, &status);
    return (status);
}

char **exec_command(char **env, command_t *cmd, int *status)
{
    int wait = !cmd->next;

    if (cmd->function < 5) {
        if (cmd->fd_out == -2) {
            cmd->fd_out = 1;
        }
        env = BUILTINS[cmd->function](env, cmd, status);
    }
    else {
        *status = exec_binary(env, cmd, wait);
    }
    if (cmd->fd_out > 2)
        close(cmd->fd_out);
    return (env);
}