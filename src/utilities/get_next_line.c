/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** Contains the get_next_line function
*/

#include <malloc.h>
#include <unistd.h>

static int find_char(char const *str, char const to_find, int const len)
{
    int pos = 0;

    if (str) {
        while (pos < len && str[pos] != to_find) {
            ++pos;
        }
    }
    if (!str || pos == len) {
        pos = -1;
    }
    return (pos);
}

static char *realloc_str(char *str, int old_size, int new_size, int should_free)
{
    int pos = 0;
    char *new_str = malloc(sizeof(char) * new_size);

    if (new_str) {
        while (pos < old_size && pos < new_size) {
            new_str[pos] = str[pos];
            ++pos;
        }
    }
    if (should_free && str) {
        free(str);
    }
    return (new_str);
}

static void resize_str(char **str, char **left, int len, int new_len)
{
    int left_len = len - new_len;
    char *new_left;

    if (len > 0) {
        if (new_len == 0) {
            new_len = len + 1;
            left_len = 0;
        }
        new_left = realloc_str(&(*left)[new_len], left_len, left_len + 1, 0);
        *str = realloc_str(*left, len, new_len, 1);
        new_left[left_len] = '\0';
        (*str)[new_len - 1] = '\0';
        *left = new_left;
    }
    else {
        free(*left);
        *left = NULL;
    }
}

static char *read_line(char *buffer, char **line, int const fd, int buffer_size)
{
    int newline_pos = find_char(buffer, '\n', buffer_size);
    int read_size = 1;

    while (newline_pos == -1 && read_size > 0) {
        buffer = realloc_str(buffer, buffer_size, buffer_size + 128, 1);
        if (buffer) {
            read_size = read(fd, &buffer[buffer_size], 128);
            buffer_size += read_size;
            newline_pos = find_char(buffer, '\n', buffer_size);
        }
        else {
            read_size = 0;
        }
    }
    resize_str(line, &buffer, buffer_size, newline_pos + 1);
    if (buffer_size == 0) {
        line = NULL;
    }
    return (buffer);
}

char *get_next_line(int const fd)
{
    static char *buffer = NULL;
    char *line = NULL;
    int buffer_size = find_char(buffer, '\0', 128);

    if (fd != -1) {
        if (buffer_size == -1) {
            buffer_size = 0;
        }
        buffer = read_line(buffer, &line, fd, buffer_size);
    }
    else {
        if (buffer) {
            free(buffer);
            buffer = NULL;
        }
    }
    return (line);
}