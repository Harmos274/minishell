/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains unit tests for the get_word function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "functions/tokens_handling.h"

Test(get_word, with_standard_string)
{
    int pos = 0;
    char *word = get_word("What are you going to do about it ?", &pos);

    cr_assert(word);
    cr_assert(pos == 4);
    cr_assert_str_eq(word, "What");
    free(word);
}

Test(get_word, with_quotes)
{
    int pos = 0;
    char *word = get_word("W\'ha\'t are you going to do about it ?", &pos);

    cr_assert(word);
    cr_assert(pos == 6);
    cr_assert_str_eq(word, "What");
    free(word);
}

Test(get_word, with_pipe)
{
    int pos = 0;
    char *word = get_word("make|grep .c", &pos);

    cr_assert(word);
    cr_assert(pos == 4);
    cr_assert_str_eq(word, "make");
    free(word);
}

Test(get_word, with_quoted_pipe)
{
    int pos = 0;
    char *word = get_word("mak\"e|grep\" .c", &pos);

    cr_assert(word);
    cr_assert(pos == 11);
    cr_assert_str_eq(word, "make|grep");
    free(word);
}

Test(get_word, with_unmatched_quotes, .init=cr_redirect_stderr)
{
    int pos = 0;
    char *word = get_word("\"make tests_run", &pos);

    cr_assert(!word);
    cr_assert(pos == -1);
    cr_assert_stderr_eq_str("Unmatched '\"'\n");
    free(word);
}