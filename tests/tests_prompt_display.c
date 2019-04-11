/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains prompt display unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "functions/prompt_display.h"

Test(display_prompt, standard_status)
{
    cr_redirect_stdout();
    display_prompt(0);
    cr_assert_stdout_eq_str("> ");
}

Test(display_prompt, error_status)
{
    cr_redirect_stdout();
    display_prompt(1);
    cr_assert_stdout_eq_str("\x1B[31m> \x1B[0m");
}