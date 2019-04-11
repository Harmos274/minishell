/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains functions used to display the prompt
*/

#include "functions/str_display.h"

int display_prompt(int const shell_status)
{
    int status = 0;

    if (!shell_status) {
        status = my_putstr("> ", 1);
    }
    else {
        status = my_putstr("\x1B[31m> \x1B[0m", 1);
    }
    return (status);
}