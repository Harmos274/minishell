/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains line parsing unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "structures/token_list.h"
#include "functions/input_parsing.h"
#include "functions/tokens_handling.h"

Test(parse_line, with_standard_line)
{
    token_list_t *list = parse_line("ls -l -Ra");

    cr_assert(list && list->next && list->next->next);
    cr_assert(!list->next->next->next);
    cr_assert(list->type == WORD && list->next->type == WORD);
    cr_assert(list->next->next->type == WORD);
    cr_assert_str_eq(list->word, "ls");
    cr_assert_str_eq(list->next->word, "-l");
    cr_assert_str_eq(list->next->next->word, "-Ra");
}

Test(parse_line, with_pipe)
{
    token_list_t *list = parse_line("ls|grep /usr/bin");

    cr_assert(list && list->next && list->next->next && list->next->next->next);
    cr_assert(!list->next->next->next->next);
    cr_assert(list->type == WORD && list->next->type == PIPE);
    cr_assert(list->next->next->type == WORD);
    cr_assert(list->next->next->next->type == WORD);
    cr_assert_str_eq(list->word, "ls");
    cr_assert_str_eq(list->next->next->word, "grep");
    cr_assert_str_eq(list->next->next->next->word, "/usr/bin");
    destroy_token_list(list);
}

Test(parse_line, with_in_redirs)
{
    token_list_t *list = parse_line("cat < test << test");

    cr_assert(list && list->next && list->next->next);
    cr_assert(!list->next->next->next);
    cr_assert(list->type == WORD && list->next->type == IN_REDIR);
    cr_assert(list->next->next->type == IN_REDIR_D);
    cr_assert_str_eq(list->word, "cat");
    cr_assert_str_eq(list->next->word, "test");
    cr_assert_str_eq(list->next->next->word, "test");
    destroy_token_list(list);
}

Test(parse_line, with_out_redirs)
{
    token_list_t *list = parse_line("cat > test >> test");

    cr_assert(list && list->next && list->next->next);
    cr_assert(!list->next->next->next);
    cr_assert(list->type == WORD && list->next->type == OUT_REDIR);
    cr_assert(list->next->next->type == OUT_REDIR_D);
    cr_assert_str_eq(list->word, "cat");
    cr_assert_str_eq(list->next->word, "test");
    cr_assert_str_eq(list->next->next->word, "test");
    destroy_token_list(list);
}

Test(parse_line, with_separator)
{
    token_list_t *list = parse_line("echo tutu;echo");

    cr_assert(list && list->next && list->next->next && list->next->next->next);
    cr_assert(!list->next->next->next->next);
    cr_assert(list->type == WORD && list->next->type == WORD);
    cr_assert(list->next->next->type == SEPARATOR);
    cr_assert(list->next->next->next->type == WORD);
    cr_assert_str_eq(list->word, "echo");
    cr_assert_str_eq(list->next->word, "tutu");
    cr_assert_str_eq(list->next->next->next->word, "echo");
    destroy_token_list(list);
}

Test(parse_line, with_empty_line)
{
    token_list_t *list = parse_line("");

    cr_assert(!list);
    destroy_token_list(list);
}

Test(parse_line, with_no_in_redir_name, .init=cr_redirect_stderr)
{
    token_list_t *list = parse_line("cat <");

    cr_assert(!list);
    cr_assert_stderr_eq_str("Missing name for redirect.\n");
    destroy_token_list(list);
}

Test(parse_line, with_no_out_redir_name, .init=cr_redirect_stderr)
{
    token_list_t *list = parse_line("echo tutu > \t");

    cr_assert(!list);
    cr_assert_stderr_eq_str("Missing name for redirect.\n");
    destroy_token_list(list);
}