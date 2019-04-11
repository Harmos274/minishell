/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains pipe sequence handling functions
*/

#include <malloc.h>
#include <unistd.h>
#include "structures/exec_list.h"
#include "structures/token_list.h"
#include "structures/pipe_sequence.h"
#include "functions/prompt.h"
#include "functions/tokens_handling.h"
#include "functions/command_handling.h"
#include "functions/pipe_sequence_handling.h"

static command_t *get_last_command(command_t *commands)
{
    while (commands->next) {
        commands = commands->next;
    }
    return (commands);
}

pipe_sequence_t *create_pipe_sequence(exec_list_t *list, char **env)
{
    pipe_sequence_t *sequence = malloc(sizeof(*sequence));

    if (sequence) {
        create_redirs(list->token_list, sequence);
        if (sequence->fd_in == -1 || sequence->fd_out == -1) {
            free(sequence);
            sequence = NULL;
        }
    }
    if (sequence) {
        sequence->commands = create_commands(list->token_list, env);
        if (!sequence->commands) {
            free(sequence);
            sequence = NULL;
        }
        else {
            get_last_command(sequence->commands)->fd_out = sequence->fd_out;
        }
    }
    return (sequence);
}

static char **exec_commands(command_t *command, char **env, int *status, int fd)
{
    int pipe_fd[2] = {-1, -1};
    int pipe_status = -1;

    if (command->next) {
        pipe_status = pipe(pipe_fd);
        if (pipe_status != -1) {
            command->fd_out = pipe_fd[1];
        }
    }
    command->fd_in = fd;
    env = exec_command(env, command, status);
    if (command->next && pipe_status != -1) {
        env = exec_commands(command->next, env, status, pipe_fd[0]);
    }
    return (env);
}

char **exec_pipe_sequence(pipe_sequence_t *sequence, int *status, char **env)
{
    sequence->commands->fd_in = sequence->fd_in;
    env = exec_commands(sequence->commands, env, status, sequence->fd_in);
    if (sequence->fd_in >= 0) {
        close(sequence->fd_in);
    }
    destroy_commands(sequence->commands);
    free(sequence);
    return (env);
}