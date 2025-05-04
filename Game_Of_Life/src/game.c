/*
 * Main file
 */

#include "gol.h"

int game_of_life(int ac, char *argv[])
{
    char **map = parse_arg(ac, argv);

    if (map == NULL) return -1;

    // Free map
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    return 0;
}
