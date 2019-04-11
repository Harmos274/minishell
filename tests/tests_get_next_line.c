/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** Contains basic functionality tests for the get_next_line function
*/

#include <unistd.h>
#include <fcntl.h>
#include <criterion/criterion.h>
#include "functions/get_next_line.h"

Test(get_next_line, get_first_line)
{
    int fd = open("tests/tests_files/gnl_test_1", O_RDONLY);
    char *line;

    if (fd != -1) {
        line = get_next_line(fd);
        cr_assert_str_eq(line, "line 1");
        free(line);
    }
    get_next_line(-1);
    close(fd);
}

Test(get_next_line, get_second_line)
{
    int fd = open("tests/tests_files/gnl_test_2", O_RDONLY);
    char *line;

    if (fd != -1) {
        line = get_next_line(fd);
        free(line);
        line = get_next_line(fd);
        cr_assert_str_eq(line, "This is the second line");
        free(line);
    }
    get_next_line(-1);
    close(fd);
}

Test(get_next_line, get_last_line)
{
    int fd = open("tests/tests_files/gnl_test_1", O_RDONLY);
    char *line = malloc(1);
    char *temp;

    if (fd != -1) {
        temp = get_next_line(fd);
        while (temp) {
            free(line);
            line = temp;
            temp = get_next_line(fd);
        }
        cr_assert_str_eq(line, "last line");
        free(line);
    }
    get_next_line(-1);
    close(fd);
}

Test(get_next_line, with_empty_file)
{
    int fd = open("tests/tests_files/gnl_test_4", O_RDONLY);
    char *line;

    if (fd != -1) {
        line = get_next_line(fd);
        cr_assert(line == NULL);
    }
    get_next_line(-1);
    close(fd);
}

Test(get_next_line, with_empty_line)
{
    int fd = open("tests/tests_files/gnl_test_3", O_RDONLY);
    char *line;

    if (fd != -1) {
        line = get_next_line(fd);
        cr_assert_str_eq(line, "");
        free(line);
    }
    get_next_line(-1);
    close(fd);
}