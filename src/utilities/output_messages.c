/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** Contains functions used to display messages
*/

#include <unistd.h>

void print_help(void)
{
    write(1, "This is a small shell written in C\nIt currently supports", 56);
    write(1, "builtin functions such as cd, env, setenv, unsetenv and ", 56);
    write(1, "exit.\nIt can also launch programs located in the PATH ", 54);
    write(1, "variable of your environment\n", 29);
}