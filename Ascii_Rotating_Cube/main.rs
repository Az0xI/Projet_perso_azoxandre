// This is the main file of the project

// Inport the lib (called crate in rust) ncurses
extern crate ncurses;

// Import all ncurses function as it's own (without calling int in a struct)
use ncurses::*;

// ascii brightness = " .:-=+*#%@"
const SHADOW: [char; 10] = [' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'];

// main function
fn main() -> () {
    initscr();
    addch(SHADOW[1] as u32);
    refresh();
    getch();
    endwin();
}
