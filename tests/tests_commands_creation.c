/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains commands creation unit tests
*/

#include <criterion/criterion.h>
#include "structures/command.h"
#include "structures/exec_list.h"
#include "structures/token_list.h"
#include "structures/pipe_sequence.h"
#include "functions/input_parsing.h"
#include "functions/command_handling.h"
#include "functions/exec_list_handling.h"

Test(create_commands, with_single_word)
{
    token_list_t *tokens = parse_line("ls");
    exec_list_t *exec_list = create_exec_list(tokens);
    char *path = "PATH=/usr/bin";
    command_t *command = NULL;

    cr_assert(exec_list && exec_list->token_list && !exec_list->next);
    command = create_commands(exec_list->token_list, &path);
    cr_assert(command && !command->next);
    cr_assert_str_eq(command->words[0], "ls");
    cr_assert(!command->words[1]);
    destroy_commands(command);
}

Test(create_commands, with_multiple_words)
{
    token_list_t *tokens = parse_line("ls -lR -a");
    exec_list_t *exec_list = create_exec_list(tokens);
    char *path = "PATH=/usr/bin";
    command_t *command = NULL;

    cr_assert(exec_list && exec_list->token_list && !exec_list->next);
    command = create_commands(exec_list->token_list, &path);
    cr_assert(command && !command->next);
    cr_assert_str_eq(command->words[0], "ls");
    cr_assert_str_eq(command->words[1], "-lR");
    cr_assert_str_eq(command->words[2], "-a");
    cr_assert(!command->words[3]);
    destroy_commands(command);
}

Test(create_commands, with_pipe)
{
    token_list_t *tokens = parse_line("echo tutu | cat");
    exec_list_t *exec_list = create_exec_list(tokens);
    char *path = "PATH=/usr/bin";
    command_t *command = NULL;

    cr_assert(exec_list && exec_list->token_list && !exec_list->next);
    cr_assert(exec_list->token_list->next);
    command = create_commands(exec_list->token_list, &path);
    cr_assert(command && command->next && !command->next->next);
    cr_assert_str_eq(command->words[0], "echo");
    cr_assert_str_eq(command->words[1], "tutu");
    cr_assert(!command->words[2]);
    cr_assert_str_eq(command->next->words[0], "cat");
    cr_assert(!command->next->words[1]);
    destroy_commands(command);
}

Test(create_commands, with_redirs)
{
    token_list_t *tokens = parse_line("echo tutu > test");
    exec_list_t *exec_list = create_exec_list(tokens);
    char *path = "PATH=/usr/bin";
    command_t *command = NULL;

    cr_assert(exec_list && exec_list->token_list && !exec_list->next);
    cr_assert(exec_list->token_list->next);
    command = create_commands(exec_list->token_list, &path);
    cr_assert(command && !command->next);
    cr_assert_str_eq(command->words[0], "echo");
    cr_assert_str_eq(command->words[1], "tutu");
    cr_assert(!command->words[2]);
    destroy_commands(command);
}

Test(create_commands, with_redirs_and_pipes)
{
    token_list_t *tokens = parse_line("echo tutu | > test cat");
    exec_list_t *exec_list = create_exec_list(tokens);
    char *path = "PATH=/usr/bin";
    command_t *command = NULL;

    cr_assert(exec_list && exec_list->token_list && !exec_list->next);
    cr_assert(exec_list->token_list->next);
    command = create_commands(exec_list->token_list, &path);
    cr_assert(command && command->next && !command->next->next);
    cr_assert_str_eq(command->words[0], "echo");
    cr_assert_str_eq(command->words[1], "tutu");
    cr_assert(!command->words[2]);
    cr_assert_str_eq(command->next->words[0], "cat");
    cr_assert(!command->next->words[1]);
    destroy_commands(command);
}