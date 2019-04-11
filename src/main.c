/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains the program's main function
*/

#include "functions/prompt.h"
#include "functions/output.h"

int main(int ac, char **av, char **env)
{
    int status = 84;

    if (ac == 1) {
        status = launch_prompt(env);
    }
    else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_help();
        status = 0;
    }
    return (status);
}