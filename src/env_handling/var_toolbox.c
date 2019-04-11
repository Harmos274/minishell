/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains functons used to modify env variables
*/

#include <malloc.h>
#include "functions/env_handling.h"
#include "functions/string_toolbox.h"

int get_var_len(char **args, int args_nbr)
{
    int len = my_strlen(args[1]) + 2;

    if (args_nbr == 3 && args[2]) {
        len += my_strlen(args[2]);
    }
    return (len);
}

int find_env_var(char **env, char const *var)
{
    int pos = 0;

    while (env[pos]) {
        if (is_same_var(var, env[pos])) {
            return (pos);
        }
        ++pos;
    }
    return (-1);
}

char *get_var_value(char **env, char const *var)
{
    int env_pos = find_env_var(env, var);
    char *result = NULL;
    int pos = 0;

    if (env_pos != -1) {
        while (env[env_pos][pos] != '\0' && env[env_pos][pos] != '=') {
            ++pos;
        }
        result = &env[env_pos][pos + 1];
    }
    return (result);
}

char *create_variable(char **args, int args_nbr)
{
    char *new_var = malloc(sizeof(char) * get_var_len(args, args_nbr));
    int pos = 0;

    if (args_nbr > 0 && new_var) {
        pos = my_strcpy(args[1], new_var);
        new_var[pos] = '=';
        ++pos;
        if (args_nbr > 2 && args[2]) {
            pos += my_strcpy(args[2], &new_var[pos]);
        }
        new_var[pos] = '\0';
    }
    return (new_var);
}