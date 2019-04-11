/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains unit tests for string related functions
*/

#include <malloc.h>
#include <criterion/criterion.h>
#include "functions/string_toolbox.h"

Test(my_strlen, with_standard_string)
{
    cr_assert(my_strlen("Hide and pray it does not find you") == 34);
}

Test(my_strlen, with_empty_string)
{
    cr_assert(my_strlen("") == 0);
}

Test(get_next_occurence, non_strict)
{
    cr_assert(get_next_occurence("nnoethun|nteohuntu", 0, '|', 0) == 8);
}

Test(my_strndup, half_string)
{
    char *test = my_strndup("He will not miss a second time", 16);

    cr_assert(test);
    cr_assert_str_eq(test, "He will not miss");
    free(test);
}

Test(my_strstr, with_eq_str)
{
    cr_assert(my_strstr("Toothless", "Toothless"));
}

Test(my_strstr, with_neq_str)
{
    cr_assert(!my_strstr("Cloudjumper", "Toothless"));
}

Test(my_strstr, with_same_beggining)
{
    cr_assert(!my_strstr("Toothless", "Toothless the alpha"));
}

Test(my_strcpy, with_standard_string)
{
    char const *test = "Toothless";
    char dest[10];

    my_strcpy(test, dest);
    cr_assert_str_eq(dest, "Toothless");
}

Test(my_strcpy, with_empty_string)
{
    char const *test = "";
    char dest[1];

    my_strcpy(test, dest);
    cr_assert_str_eq(dest, "");
}