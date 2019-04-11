/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains character related functions
*/

char is_letter(char chr)
{
    if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z')) {
        return (1);
    }
    return (0);
}

char is_number(char chr)
{
    if (chr >= '0' && chr <= '9') {
        return (1);
    }
    return (0);
}

char is_alphanumerical(char chr)
{
    if (is_letter(chr) || is_number(chr)) {
        return (1);
    }
    return (0);
}