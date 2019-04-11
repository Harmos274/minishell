/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains input related functions prototypes
*/

#include "structures/command.h"

#ifndef PROMPT_H_
    #define PROMPT_H_
    char **exec_command(char **env, command_t *command, int *status);
    char **get_command(char const *str, int const args_nbr);
    void free_args(char **args, int const args_nbr);
    int launch_prompt(char **env);
    int get_words_nbr(char const *str);
#endif /* !PROMPT_H_ */