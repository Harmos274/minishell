/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains functions used to manipulate shell status
*/

int set_stop(int status)
{
    status |= 0xF0000;
    return (status);
}

int should_stop(int status)
{
    status &= 0xFFFF0000;
    return (status & 0xF0000);
}

int get_status_code(int status)
{
    status &= 0xFFFF;
    return (status);
}