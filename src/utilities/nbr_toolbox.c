/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains nbr related functions
*/

static int get_pos_nbr(char const *str)
{
    int pos = 0;
    int nbr = 0;

    while (str[pos] != '\0') {
        nbr *= 10;
        nbr += str[pos] - '0';
        ++pos;
    }
    return (nbr);
}

static int get_neg_nbr(char const *str)
{
    int pos = 1;
    int nbr = 0;

    while (str[pos] != '\0') {
        nbr *= 10;
        nbr -= str[pos] - '0';
        ++pos;
    }
    return (nbr);
}

int my_getnbr(char const *str)
{
    int nbr = 0;

    if (str[0] == '-') {
        nbr = get_neg_nbr(str);
    }
    else {
        nbr = get_pos_nbr(str);
    }
    return (nbr);
}

int is_nbr(char const *str)
{
    int pos = 0;

    if (str[0] == '-') {
        ++pos;
    }
    while (str[pos] != '\0') {
        if (str[pos] < '0' || str[pos] > '9') {
            return (0);
        }
        ++pos;
    }
    return (1);
}