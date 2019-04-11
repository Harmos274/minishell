/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains functions used to get user input
*/

#include <malloc.h>
#include <unistd.h>
#include "structures/pipe_sequence.h"
#include "structures/exec_list.h"
#include "functions/pipe_sequence_handling.h"
#include "functions/exec_list_handling.h"
#include "functions/status_handling.h"
#include "functions/prompt_display.h"
#include "functions/string_toolbox.h"
#include "functions/input_parsing.h"
#include "functions/get_next_line.h"
#include "functions/env_handling.h"
#include "functions/builtin.h"
#include "functions/prompt.h"

static char **exec_exec_list(exec_list_t *list, char **env, int *status)
{
    pipe_sequence_t *sequence = NULL;

    if (check_exec_list(list)) {
        sequence = create_pipe_sequence(list, env);
        if (sequence) {
            env = exec_pipe_sequence(sequence, status, env);
        }
    }
    return (env);
}

static char **get_input(char **env, int *status)
{
    char *input = get_next_line(0);
    exec_list_t *exec_list = create_exec_list(parse_line(input));
    exec_list_t *prev = NULL;

    if (!input) {
        get_next_line(-1);
        *status = set_stop(*status);
    }
    if (exec_list && check_exec_list(exec_list)) {
        while (exec_list && !should_stop(*status)) {
            env = exec_exec_list(exec_list, env, status);
            prev = exec_list;
            exec_list = exec_list->next;
            free(prev);
        }
    }
    free(input);
    return (env);
}

static int prompt_loop(char **env)
{
    int status = 0;
    int wrote = 0;

    while (!should_stop(status)) {
        wrote = display_prompt(status);
        if (wrote) {
            env = get_input(env, &status);
        }
        else {
            status = set_stop(status);
        }
    }
    get_next_line(-1);
    write(1, "exit\n", 5);
    return (get_status_code(status));
}

int launch_prompt(char **env)
{
    char **new_env = envdup(env);
    int new_size = 0;
    char *path = NULL;
    int status = 84;

    if (new_env) {
        path = get_var_value(env, "PATH");
        if (!path || path[0] == '\0') {
            new_size = get_env_size(new_env);
            new_env = enlarge_env(new_env);
            new_env[new_size - 1] = my_strndup("PATH=/usr/bin", 13);
        }
        status = prompt_loop(new_env);
    }
    free_env(new_env);
    return (status);
}