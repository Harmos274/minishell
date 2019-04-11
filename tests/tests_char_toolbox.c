/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** Contains char related functions' prototypes
*/

#include <criterion/criterion.h>
#include "functions/char_toolbox.h"

Test(is_letter, with_every_letter)
{
    char letter = 'A';

    while (letter <= 'Z') {
        cr_assert(is_letter(letter));
        ++letter;
    }
    letter = 'a';
    while (letter <= 'z') {
        cr_assert(is_letter(letter));
        ++letter;
    }
}

Test(is_letter, with_every_non_letter)
{
    char letter = 0;

    while (letter < 'A') {
        cr_assert(!is_letter(letter));
        ++letter;
    }
    letter = 'Z' + 1;
    while (letter < 'a') {
        cr_assert(!is_letter(letter));
        ++letter;
    }
    letter = 'z' + 1;
    while (letter < 127) {
        cr_assert(!is_letter(letter));
        ++letter;
    }
    cr_assert(!is_letter(letter));
}

Test(is_number, with_every_digit)
{
    char number = '0';

    while (number <= '9') {
        cr_assert(is_number(number));
        ++number;
    }
}

Test(is_number, with_every_non_number)
{
    char number = 0;

    while (number < '0') {
        cr_assert(!is_number(number));
        ++number;
    }
    number = '9' + 1;
    while (number < 127) {
        cr_assert(!is_number(number));
        ++number;
    }
    cr_assert(!is_number(number));
}

Test(is_alphanumerical, with_every_alphanumerical)
{
    char alphanum = '0';

    while (alphanum <= '9') {
        cr_assert(is_alphanumerical(alphanum));
        ++alphanum;
    }
    alphanum = 'A';
    while (alphanum <= 'Z') {
        cr_assert(is_alphanumerical(alphanum));
        ++alphanum;
    }
    alphanum = 'a';
    while (alphanum <= 'z') {
        cr_assert(is_alphanumerical(alphanum));
        ++alphanum;
    }
}

Test(is_alphanumerical, with_every_non_alphanumerical)
{
    char alphanum = '\0';

    while (alphanum < '0') {
        cr_assert(!is_alphanumerical(alphanum));
        ++alphanum;
    }
    alphanum = '9' + 1;
    while (alphanum < 'A') {
        cr_assert(!is_alphanumerical(alphanum));
        ++alphanum;
    }
    alphanum = 'Z' + 1;
    while (alphanum < 'a') {
        cr_assert(!is_alphanumerical(alphanum));
        ++alphanum;
    }
}