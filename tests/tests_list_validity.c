/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains unit tests for functions used to test an exec list validity
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "structures/exec_list.h"
#include "structures/token_list.h"
#include "functions/input_parsing.h"
#include "functions/exec_list_handling.h"

Test(check_exec_list, with_valid_list)
{
    token_list_t *tokens = parse_line("ls -l -Ra | grep /bin ; echo done");
    exec_list_t *list = create_exec_list(tokens);

    cr_assert(list);
    cr_assert(check_exec_list(list));
    destroy_exec_list(list);
}

Test(check_exec_list, with_invalid_null_command, .init=cr_redirect_stderr)
{
    token_list_t *tokens = parse_line("ls -l -Ra || grep /bin ; echo done");
    exec_list_t *list = create_exec_list(tokens);

    cr_assert(list);
    cr_assert(!check_exec_list(list));
    cr_assert_stderr_eq_str("Invalid null command.\n");
    destroy_exec_list(list);
}

Test(check_exec_list, with_invalid_null_command_end, .init=cr_redirect_stderr)
{
    token_list_t *tokens = parse_line("ls -l -Ra | grep /bin ; echo done | ");
    exec_list_t *list = create_exec_list(tokens);

    cr_assert(list);
    cr_assert(!check_exec_list(list));
    cr_expect_stderr_eq_str("Invalid null command.\n");
    destroy_exec_list(list);
}

Test(check_exec_list, with_ambiguous_output_redir)
{
    token_list_t *tokens = parse_line("echo tutu > test | cat < test");
    exec_list_t *list = create_exec_list(tokens);

    cr_redirect_stderr();
    cr_assert(list);
    cr_assert(!check_exec_list(list));
    cr_assert_stderr_eq_str("Ambiguous output redirect.\n");
    destroy_exec_list(list);
}

Test(check_exec_list, with_ambiguous_input_redir)
{
    token_list_t *tokens = parse_line("echo tutu | cat < test");
    exec_list_t *list = create_exec_list(tokens);

    cr_redirect_stderr();
    cr_assert(list);
    cr_assert(!check_exec_list(list));
    cr_assert_stderr_eq_str("Ambiguous input redirect.\n");
    destroy_exec_list(list);
}

Test(check_exec_list, with_too_many_output_redir)
{
    token_list_t *tokens = parse_line("echo tutu > test | echo tutu > test");
    exec_list_t *list = create_exec_list(tokens);

    cr_redirect_stderr();
    cr_assert(list);
    cr_assert(!check_exec_list(list));
    cr_assert_stderr_eq_str("Ambiguous output redirect.\n");
    destroy_exec_list(list);
}

Test(check_exec_list, with_too_many_input_redir)
{
    token_list_t *tokens = parse_line("cat < test | cat < test");
    exec_list_t *list = create_exec_list(tokens);

    cr_redirect_stderr();
    cr_assert(list);
    cr_assert(!check_exec_list(list));
    cr_assert_stderr_eq_str("Ambiguous input redirect.\n");
    destroy_exec_list(list);
}

Test(check_exec_list, with_valid_redirs)
{
    token_list_t *tokens = parse_line("cat < test | cat > test");
    exec_list_t *list = create_exec_list(tokens);

    cr_assert(list);
    cr_assert(check_exec_list(list));
    destroy_exec_list(list);
}

Test(check_exec_list, with_weird_valid_redirs)
{
    token_list_t *tokens = parse_line("<test cat|>test cat");
    exec_list_t *list = create_exec_list(tokens);

    cr_assert(list);
    cr_assert(check_exec_list(list));
    destroy_exec_list(list);
}