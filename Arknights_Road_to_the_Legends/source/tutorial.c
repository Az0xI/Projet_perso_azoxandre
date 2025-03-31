/*
  file with the tutorial of the game
*/

#include "AK_RTTL.h"
#include <curses.h>
#include <stdlib.h>

void print_tutorial(WINDOW *menu, int where)
{
    mvwprintw(menu, 0, 2, "Tutorial");
}

int tutorial(void)
{
    WINDOW *menu = newwin(10, 10, LINES / 3, (COLS / 2) - 4);
    int live = 1;
    int where = 0;

    while (live == 1) {
        menu = newwin(10, 10, LINES / 2, (COLS / 2) - 4);
        clear();
        refresh();
        print_tutorial(menu, where);
        wrefresh(menu);
    }
    return 0;
}
