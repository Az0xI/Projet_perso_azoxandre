// This is the main file of the project

extern crate ncurses;

use ncurses::*;

// ascii brightness = " .:-=+*#%@"
const SHADOW: [char; 10] = [' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'];

// main function
fn main() {
    initscr();
    addch(SHADOW[1]);
    refresh();
    getch();
    endwin();
}
