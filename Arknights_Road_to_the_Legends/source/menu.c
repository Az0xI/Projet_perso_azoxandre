/*
  file with the menu of the game
*/

#include "AK_RTTL.h"
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

void print_title(FILE *fs)
{
    char *buffer = "\0";
    size_t size = 0;
    int ret = getline(&buffer, &size, fs);

    while (ret != -1) {
        printw("%s", buffer);
        ret = getline(&buffer, &size, fs);
    }
}

void print_menu(WINDOW *menu, int where)
{
    if (where == 0)
        wattron(menu, A_REVERSE);
    mvwprintw(menu, 0, 2, "Play");
    wattroff(menu, A_REVERSE);
    if (where == 1)
        wattron(menu, A_REVERSE);
    mvwprintw(menu, 2, 0, "Tutorial");
    wattroff(menu, A_REVERSE);
    if (where == 2)
        wattron(menu, A_REVERSE);
    mvwprintw(menu, 4, 2, "Exit");
    wattroff(menu, A_REVERSE);
}

int menu(void)
{
    WINDOW *menu = newwin(10, 10, LINES / 3, (COLS / 2) - 4);
    FILE *fs = fopen("asset/text/title", "w");
    int live = 1;
    int where = 0;

    while (live == 1) {
        refresh();
        if (COLS <= 98) {
            printw("This window is to small to play\n");
            refresh();
        } else {
            print_title(fs);
            print_menu(menu, where);
            wrefresh(menu);
            event_menu_poll(getch(), &live, &where, &live);
        }
        clear();
    }
    return 0;
}
