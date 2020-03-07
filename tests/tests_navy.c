/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** tests_navy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "my.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_get_redirected_stderr();
    cr_redirect_stderr();
}

Test(navy, file_not_existing, .init = redirect_all_stdout)
{
    char *test[] = {"./navy", "prout"};

    cr_assert_eq(navy(2, test), 84);
}

Test(navy, diagonal_boats, .init = redirect_all_stdout)
{
    char *test[] = {"./navy", "./tests/not_valid_maps/diagonal_boats"};

    cr_assert_eq(navy(2, test), 84);
}

Test(navy, empty_file, .init = redirect_all_stdout)
{
    char *test[] = {"./navy", "./tests/not_valid_maps/empty_file"};

    cr_assert_eq(navy(2, test), 84);
}

Test(navy, not_corresponding_boats, .init = redirect_all_stdout)
{
    char *test[] = {"./navy",
    "./tests/not_valid_maps/not_corresponding_boats"};

    cr_assert_eq(navy(2, test), 84);
}

Test(navy, not_enough_boats, .init = redirect_all_stdout)
{
    char *test[] = {"./navy", "./tests/not_valid_maps/not_enough_boats"};

    cr_assert_eq(navy(2, test), 84);
}

Test(navy, not_existing_pos, .init = redirect_all_stdout)
{
    char *test[] = {"./navy", "./tests/not_valid_maps/not_existing_pos"};

    cr_assert_eq(navy(2, test), 84);
}

Test(navy, superposed_boats, .init = redirect_all_stdout)
{
    char *test[] = {"./navy", "./tests/not_valid_maps/superposed_boats"};

    cr_assert_eq(navy(2, test), 84);
}

Test(navy, too_big_boats, .init = redirect_all_stdout)
{
    char *test[] = {"./navy", "./tests/not_valid_maps/too_big_boats"};

    cr_assert_eq(navy(2, test), 84);
}

Test(navy, too_much_boats, .init = redirect_all_stdout)
{
    char *test[] = {"./navy", "./tests/not_valid_maps/too_much_boats"};

    cr_assert_eq(navy(2, test), 84);
}

Test(navy, too_small_boats, .init = redirect_all_stdout)
{
    char *test[] = {"./navy", "./tests/not_valid_maps/too_small_boats"};

    cr_assert_eq(navy(2, test), 84);
}