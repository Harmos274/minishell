/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains command handling functions' prototypes
*/

#include "structures/command.h"
#include "structures/token_list.h"

#ifndef COMMAND_HANDLING_H_
    #define COMMAND_HANDLING_H_
    command_t *create_commands(token_list_t *list, char **env);
    char *get_correct_path(char *binary, char *path_var);
    void destroy_commands(command_t *command);
#endif /* !COMMAND_HANDLING_H_ */