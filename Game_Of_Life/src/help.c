/*
 * Help file, print the help info
 */

#include "gol.h"

int print_help(void)
{
    printf("USAGE\n\t./gol [file]\n\n");
    printf("DESCRIPTION\n\t[file]: a file with the map to initialize,");
    printf("it has to be a rectangle map, with cells = \"x\" char and \".\" for non cells\n\n");
    printf("\tIf there isn't any map, the user can create one using the builtin map editor");
    return 0;
}
