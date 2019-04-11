/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains the command struct
*/

#ifndef COMMAND_H_
    #define COMMAND_H_
    typedef struct command_s {
        int words_nbr;
        char **words;
        char *path;
        int function;
        int fd_in;
        int fd_out;
        struct command_s *next;
    } command_t;
#endif /* !COMMAND_H_ */