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
    int nb_neigh = map[i][j] == '.' ? 0 : -1;
    int x = i <= 0 ? 0 : i - 1;
    int y = j <= 0 ? 0 : j - 1;

    //printf("mapij = %c nb_voisin = %i\n", map[i][j], nb_voisin);
    // Check for neighbour and error handling
    for (; x <= i + 1 && map[x] != NULL; x++) {
        //printf("x = %i y = %i\n", x, y);
        for (; y <= j + 1 && map[x][y] != '\0'; y++) {
            nb_neigh = (map[x][y] != '.' ? nb_neigh + 1 : nb_neigh);
        }
        y = j <= 0 ? 0 : j - 1;
    }
    printf("%i", nb_neigh);
    // Modify array with the game rules
    if ((nb_neigh < 2 || nb_neigh > 3) && map[i][j] == 'X') map[i][j] = 'O';
    if ((nb_neigh < 2 || nb_neigh > 3) && map[i][j] != 'X') map[i][j] = '.';
    if (nb_neigh == 3) map[i][j] = 'X';
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
            printf("\n");
        }
        sleep(3);
    }

    // Free map
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    return 0;
}
