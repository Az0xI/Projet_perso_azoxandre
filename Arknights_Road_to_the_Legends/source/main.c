/*
** ARKNIGHTS Road To The Legend is an JRPG/Roguelike games in TUI based on the
** Arknights licence and World,
*/

#include "AK_RTTL.h"
#include <curses.h>


//Init the screen with play, tutorials, option, quit

int main()
{
    initscr();
    keypad(stdscr, TRUE);
    menu();
    endwin();
    return 0;
}
