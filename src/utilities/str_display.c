/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains string display functions
*/

#include <wait.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "functions/string_toolbox.h"

int my_putstr(char const *str, int const fd)
{
    int len = my_strlen(str);
    int status = write(fd, str, len);

    if (status == len) {
        status = 1;
    }
    else {
        status = 0;
    }
    return (status);
}

int display_unmatched(char const chr, int const fd)
{
    int status = 1;

    status = my_putstr("Unmatched '", fd);
    if (status) {
        status = write(fd, &chr, 1);
        if (status) {
            status = my_putstr("'\n", fd);
        }
    }
    return (status);
}

int my_perror(char const *prefix)
{
    char *error = strerror(errno);
    int status = 1;

    if (prefix) {
        status = my_putstr(prefix, 2);
    }
    if (status) {
        status = my_putstr(": ", 2);
        if (status) {
            status = my_putstr(error, 2);
        }
        if (status) {
            status = my_putstr(".\n", 2);
        }
    }
    return (status);
}

void display_signal(int const status)
{
    char *signal = NULL;

    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGFPE) {
            write(2, "Floating exception", 18);
        }
        else {
            signal = strsignal(WTERMSIG(status));
            write(2, signal, my_strlen(signal));
        }
        if (WCOREDUMP(status)) {
            write(2, " (core dumped)", 14);
        }
        write(2, "\n", 1);
    }
}