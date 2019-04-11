/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains functions used to create redirections
*/

#include <malloc.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "structures/exec_list.h"
#include "functions/pipe_sequence_handling.h"
#include "functions/str_display.h"
#include "functions/get_next_line.h"
#include "functions/string_toolbox.h"

static int create_heredoc(char const *end_word)
{
    int pipefd[2] = {-1, -1};
    char *buffer = NULL;
    int status = 1;

    status = pipe(pipefd);
    if (status != -1) {
        write(1, "? ", 2);
        buffer = get_next_line(0);
        status = 1;
        while (status && buffer && !my_strstr(buffer, end_word)) {
            status = my_putstr(buffer, pipefd[1]);
            status &= my_putstr("\n", pipefd[1]);
            free(buffer);
            write(1, "? ", 2);
            buffer = get_next_line(0);
        }
        free(buffer);
        close(pipefd[1]);
    }
    return (pipefd[0]);
}

static int create_in_redir(token_type_t type, char const *path)
{
    int fd = 1;

    if (type == IN_REDIR) {
        fd = open(path, O_RDONLY);
        if (fd == -1) {
            my_perror(path);
        }
    }
    else if (type == IN_REDIR_D) {
        fd = create_heredoc(path);
        if (fd == -1) {
            my_perror(NULL);
        }
    }
    return (fd);
}

static int create_out_redir(token_type_t type, char const *path)
{
    int fd = -1;

    if (type == OUT_REDIR) {
        fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    }
    else if (type == OUT_REDIR_D) {
        fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
    }
    if (fd == -1) {
        my_perror(path);
    }
    return (fd);
}

void create_redirs(token_list_t *list, pipe_sequence_t *sequence)
{
    sequence->fd_in = -2;
    sequence->fd_out = -2;
    while (list) {
        if (list->type == IN_REDIR || list->type == IN_REDIR_D) {
            sequence->fd_in = create_in_redir(list->type, list->word);
            free(list->word);
        }
        else if (list->type == OUT_REDIR || list->type == OUT_REDIR_D) {
            sequence->fd_out = create_out_redir(list->type, list->word);
            free(list->word);
        }
        list = list->next;
    }
}