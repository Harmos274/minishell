/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains the pipe sequence struct
*/

#include "structures/command.h"

#ifndef PIPE_SEQUENCE_H_
    #define PIPE_SEQUENCE_H_
    typedef struct pipe_sequence_s {
        command_t *commands;
        int fd_in;
        int fd_out;
    } pipe_sequence_t;
#endif /* !PIPE_SEQUENCE_H_ */