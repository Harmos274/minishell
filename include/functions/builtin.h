/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains builtin functions prototypes
*/

#include "structures/command.h"

#ifndef BUILTIN_H_
    #define BUILTIN_H_
    char **builtin_cd(char **env, command_t *command, int *status);
    char **builtin_env(char **env, command_t *command, int *status);
    char **builtin_exit(char **env, command_t *command, int *status);
    char **builtin_setenv(char **env, command_t *command, int *status);
    char **builtin_unsetenv(char **env, command_t *command, int *status);
#endif /* !BUILTIN_H_ */