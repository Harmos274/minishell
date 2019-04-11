/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains functions used to handle commands
*/

#include <malloc.h>
#include "resources/token_type.h"
#include "resources/builtins_commands.h"
#include "structures/command.h"
#include "structures/exec_list.h"
#include "functions/str_display.h"
#include "functions/env_handling.h"
#include "structures/token_list.h"
#include "functions/string_toolbox.h"
#include "functions/command_handling.h"
#include "functions/tokens_handling.h"

void destroy_commands(command_t *command)
{
    int pos = 0;

    if (command->path) {
        free(command->path);
    }
    else if (command->function == 5) {
        display_not_found(command->words[0]);
    }
    while (command->words[pos]) {
        free(command->words[pos]);
        ++pos;
    }
    free(command->words);
    if (command->next) {
        destroy_commands(command->next);
    }
    free(command);
}

static int get_word_nbr(token_list_t *list)
{
    int word_nbr = 0;

    while (list && list->type != PIPE) {
        if (list->type == WORD) {
            ++word_nbr;
        }
        list = list->next;
    }
    return (word_nbr);
}

static void transfer_words(token_list_t *list, command_t *command, char **env)
{
    token_list_t *prev = NULL;
    int pos = 0;

    while (list && list->type != PIPE) {
        if (list->type == WORD) {
            command->words[pos] = list->word;
            ++pos;
        }
        prev = list;
        list = list->next;
        free(prev);
    }
    if (list && list->type == PIPE) {
        command->next = create_commands(list->next, env);
        free(list);
    }
    else {
        command->next = NULL;
    }
}

static int get_command_function(command_t *command, char **env)
{
    char *path_var = NULL;
    int pos = 0;

    while (pos < 5) {
        if (my_strstr(command->words[0], COMMANDS[pos])) {
            return (pos);
        }
        ++pos;
    }
    path_var = get_var_value(env, "PATH");
    command->path = get_correct_path(command->words[0], path_var);
    return (pos);
}

command_t *create_commands(token_list_t *list, char **env)
{
    command_t *command = malloc(sizeof(*command));
    int word_nbr = get_word_nbr(list);

    if (command) {
        command->words = malloc(sizeof(char *) * (word_nbr + 1));
        if (command->words) {
            command->fd_in = -2;
            command->fd_out = -2;
            command->words_nbr = word_nbr;
            command->words[word_nbr] = NULL;
            command->path = NULL;
            transfer_words(list, command, env);
            command->function = get_command_function(command, env);
        }
    }
    return (command);
}