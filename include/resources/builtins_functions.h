/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains builtins function pointers
*/

#include "structures/command.h"
#include "functions/builtin.h"

#ifndef BUILTINS_FUNCTIONS_H_
    #define BUILTINS_FUNCTIONS_H_
    char **(* const BUILTINS[])(char **env, command_t *command, int *ret) = {
        &builtin_cd,
        &builtin_env,
        &builtin_setenv,
        &builtin_unsetenv,
        &builtin_exit,
    };
#endif /* !BUILTINS_FUNCTIONS_H_ */