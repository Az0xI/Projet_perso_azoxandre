/*
 * Main file
 */

#include "gol.h"

int main(int ac, char *argv[])
{
    if (ac == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
        return print_help();
    initscr();
    keypad(stdscr, TRUE);

    int ret_value = game_of_life(ac, argv);

    endwin();
    return ret_value;
}
