/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains file related functions' prototypes
*/

#include <criterion/criterion.h>
#include "functions/file_toolbox.h"

Test(path_concat, with_no_separator)
{
    char *new_path = path_concat("/usr/bin", "ls");

    cr_assert(new_path);
    cr_assert_str_eq(new_path, "/usr/bin/ls");
    free(new_path);
}

Test(path_concat, with_separator_on_arg1)
{
    char *new_path = path_concat("/usr/bin/", "ls");

    cr_assert(new_path);
    cr_assert_str_eq(new_path, "/usr/bin/ls");
    free(new_path);
}

Test(path_concat, with_separator_on_arg2)
{
    char *new_path = path_concat("/usr/bin", "ls/");

    cr_assert(new_path);
    cr_assert_str_eq(new_path, "/usr/bin/ls/");
    free(new_path);
}

Test(is_file_executable, with_executable_file)
{
    cr_assert(is_file_executable("unit_tests"));
}

Test(is_file_executable, with_non_executable_file)
{
    cr_assert(!is_file_executable("Makefile"));
}