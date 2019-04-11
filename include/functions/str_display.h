/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains string display functions
*/

#ifndef STR_DISPLAY_H_
    #define STR_DISPLAY_H_
    int my_perror(char const *prefix);
    void display_signal(int const status);
    int my_putstr(char const *str, int const fd);
    int display_unmatched(char const chr, int const fd);
#endif /* !STR_DISPLAY_H_ */