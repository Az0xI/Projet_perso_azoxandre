/*
 * Main file
 */

#include "gol.h"

static void display_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            if (map[i][j] == 'O') map[i][j] = '.';
        // mvprintw(i, 0, map[i]);
        printf("%s\n", map[i]);
    }
    // refresh();
}

static void process_changes(char **map, int i, int j)
{
    int nb_voisin = 0;
    int x = i - 1;
    int y = j - 1;

    // Check for neighbour and error handling
    for (; x <= i + 1; x++) {
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        for (; y <= j + 1; y++) {
            nb_voisin = (map[x][y] != '.' ? nb_voisin + 1 : nb_voisin);
            printf("mapxy = %c x = %i y = %i\n",map[x][y], x, y);
        }
        y = j == 0 ? j : j - 1;
    }
    printf("\n");

    // Modify array with the game rules
    if ((nb_voisin < 2 || nb_voisin > 3) && map[x][y] == 'X') map[x][y] = 'O';
    if ((nb_voisin < 2 || nb_voisin > 3) && map[x][y] != 'X') map[x][y] = '.';
    if (nb_voisin == 3) map[x][y] = 'X';
}

int game_of_life(int ac, char *argv[])
{
    char **map = parse_arg(ac, argv);

    if (map == NULL) return -1;

    // Game loop
    while (true) {
        for (int i = 0; map[i] != NULL; i++)
            for (int j = 0; map[i][j] != '\0'; j++)
                process_changes(map, i, j);
        sleep(5);
        display_map(map);
    }

    // Free map
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    return 0;
}
