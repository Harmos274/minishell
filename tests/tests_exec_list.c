/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains unit tests for exec list handling
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include "structures/exec_list.h"
#include "structures/token_list.h"
#include "functions/input_parsing.h"
#include "functions/tokens_handling.h"
#include "functions/exec_list_handling.h"

Test(create_exec_list, with_standard_tokens)
{
    token_list_t *tokens = parse_line("ls -la -R");
    exec_list_t *list = create_exec_list(tokens);

    cr_assert(tokens && list);
    cr_assert(list->token_list == tokens);
    cr_assert(!list->next);
    cr_assert(tokens && tokens->next && tokens->next->next);
    cr_assert(!tokens->next->next->next);
    cr_assert_str_eq(tokens->word, "ls");
    cr_assert_str_eq(tokens->next->word, "-la");
    cr_assert_str_eq(tokens->next->next->word, "-R");
    destroy_exec_list(list);
}

Test(create_exec_list, with_separator)
{
    token_list_t *tokens = parse_line("ls ; echo tutu");
    exec_list_t *list = create_exec_list(tokens);

    cr_assert(tokens && list);
    cr_assert(list->next);
    cr_assert(list->token_list && !list->token_list->next);
    cr_assert(list->next->token_list && list->next->token_list->next);
    cr_assert(!list->next->token_list->next->next);
    cr_assert_str_eq(list->token_list->word, "ls");
    cr_assert_str_eq(list->next->token_list->word, "echo");
    cr_assert_str_eq(list->next->token_list->next->word, "tutu");
    destroy_exec_list(list);
}

Test(create_exec_list, with_consecutive_separators)
{
    token_list_t *tokens = parse_line("ls ;;  ; ;  ;; \t   ; echo tutu");
    exec_list_t *list = create_exec_list(tokens);

    cr_assert(tokens && list);
    cr_assert(list->next);
    cr_assert(list->token_list && !list->token_list->next);
    cr_assert(list->next->token_list && list->next->token_list->next);
    cr_assert(!list->next->token_list->next->next);
    cr_assert_str_eq(list->token_list->word, "ls");
    cr_assert_str_eq(list->next->token_list->word, "echo");
    cr_assert_str_eq(list->next->token_list->next->word, "tutu");
    destroy_exec_list(list);
}

Test(create_exec_list, with_separator_at_end)
{
    token_list_t *tokens = parse_line("echo tutu ;");
    exec_list_t *list = create_exec_list(tokens);

    cr_assert(tokens && list);
    cr_assert(list->token_list && !list->next);
    cr_assert(list->token_list->type == WORD);
    cr_assert(list->token_list->next->type == WORD);
    cr_assert_str_eq(list->token_list->word, "echo");
    cr_assert_str_eq(list->token_list->next->word, "tutu");
    destroy_exec_list(list);
}

Test(create_exec_list, with_separator_at_beggining)
{
    token_list_t *tokens = parse_line("; echo tutu");
    exec_list_t *list = create_exec_list(tokens);

    cr_assert(tokens && list);
    cr_assert(list->token_list && !list->next);
    cr_assert(list->token_list->type == WORD);
    cr_assert(list->token_list->next->type == WORD);
    cr_assert_str_eq(list->token_list->word, "echo");
    cr_assert_str_eq(list->token_list->next->word, "tutu");
    destroy_exec_list(list);
}