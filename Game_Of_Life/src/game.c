/*
 * Main file
 */

#include "gol.h"

static void display_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == TO_DIE) map[i][j] = DEAD;
            if (map[i][j] == TO_LIVE) map[i][j] = LIVE;
        }
        mvprintw(i, 0, map[i]);
    }
    refresh();
}

static void process_changes(char **map, int i, int j)
{
    int nb_neigh = map[i][j] == DEAD ? 0 : -1;
    int x = i <= 0 ? 0 : i - 1;
    int y = j <= 0 ? 0 : j - 1;

    // Check for neighbour and error handling
    for (; x <= i + 1 && map[x] != NULL; x++) {
        for (; y <= j + 1 && map[x][y] != '\0'; y++)
            if (map[x][y] == LIVE || map[x][y] == TO_DIE) nb_neigh++;
        y = j <= 0 ? 0 : j - 1;
    }

    // Modify array with the game rules
    if (nb_neigh < 2 || nb_neigh > 3) if (map[i][j] == LIVE) map[i][j] = TO_DIE;
    if (nb_neigh == 3) map[i][j] = TO_LIVE;
}

int game_of_life(int ac, char *argv[])
{
    char **map = parse_arg(ac, argv);

    if (map == NULL) return -1;

    // Game loop
    while (true) {
        display_map(map);
        for (int i = 0; map[i] != NULL; i++) {
            for (int j = 0; map[i][j] != '\0'; j++)
                process_changes(map, i, j);
        }
        sleep(2);
    }

    // Free map
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    return 0;
}
