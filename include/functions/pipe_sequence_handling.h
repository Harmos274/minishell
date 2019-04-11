/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains pipe sequence related functions' prototypes
*/

#include "structures/token_list.h"
#include "structures/pipe_sequence.h"

#ifndef PIPE_SEQUENCE_HANDLING_H_
    #define PIPE_SEQUENCE_HANDLING_H_
    pipe_sequence_t *create_pipe_sequence(exec_list_t *list, char **env);
    void create_redirs(token_list_t *list, pipe_sequence_t *sequence);
    char **exec_pipe_sequence(pipe_sequence_t *seq, int *status, char **env);
#endif /* !PIPE_SEQUENCE_HANDLING_H_ */