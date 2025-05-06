/*
** Headers file
*/

#ifndef GAME_OF_LIFE_H_
    #define GAME_OF_LIFE_H_

    #include <curses.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <linux/limits.h>

    #define DEFAULT_LENGHT 30
    #define DEFAULT_WIDTH 30
    #define LIVE 'X'
    #define TO_LIVE 'Y'
    #define DEAD '.'
    #define TO_DIE 'O'


// print the help message //
int print_help(void);

// Start the game //
int game_of_life(int ac, char *argv[]);

// PArse args and return a map //
char **parse_arg(int ac, char *argv[]);

#endif /* GAME_OF_LIFE_H_ */
