/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** Contains prototypes of string related functions
*/

#ifndef STRING_TOOLBOX_H_
    #define STRING_TOOLBOX_H_
    int is_nbr(char const *str);
    int my_getnbr(char const *str);
    int my_strlen(char const *str);
    int my_strcpy(char const *source, char *dest);
    char *my_strndup(char const *str, int const to_copy);
    int my_strstr(char const *str1, char const *str2);
    int get_next_occurence(char const *str, int pos, char const to_find, int s);
#endif /* !STRING_TOOLBOX_H_ */