/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains functions used to run the exit builtin
*/

#include <stdlib.h>
#include "structures/command.h"
#include "functions/status_handling.h"
#include "functions/command_handling.h"
#include "functions/string_toolbox.h"
#include "functions/get_next_line.h"
#include "functions/env_handling.h"

char **builtin_exit(char **env, command_t *command, int *status)
{
    if (command->next) {
        return (env);
    }
    if (command->function == 4 && command->words_nbr == 2) {
        if (is_nbr(command->words[1])) {
            *status = my_getnbr(command->words[1]);
        }
    }
    else {
        *status = 0;
    }
    *status = set_stop(*status);
    return (env);
}