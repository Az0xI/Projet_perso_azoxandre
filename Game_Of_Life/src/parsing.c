/*
 * Main file
 */

#include "gol.h"

static char **map_from_file(char *path)
{
    // Handle path potential errors
    if (access(path, X_OK) == -1) {
        fprintf(stderr, "Invalid path: File does not exist.\n");
        return NULL;
    }
    if (access(path, R_OK) == -1) {
        fprintf(stderr, "Invalid access, doesn't have the right to open the file.\n");
    }

    FILE *file = fopen(path, "r");

    if (file == NULL) {
        fprintf(stderr, "File openning has failed.\n");
        return NULL;
    }

    // Read and parse the file
    int nb_lines = 0;
    char *buffer = NULL;
    size_t size = 0;

    while (getline(&buffer, &size, file) != -1)
        nb_lines++;
    rewind(file); // FUnction to set the file position to the beggining of the file

    // Fill the map array
    char **map = malloc(sizeof(char) * (nb_lines + 1));

    if (map == NULL) {
        fprintf(stderr, "Malloc has failed\n");
        return NULL;
    }
    for (int i = 0; getline(&buffer, &size, file) != -1; i++) {
        if (buffer[size - 1] == '\n')
            buffer[size - 1] = '\0';
        map[i] = strdup(buffer);
    }
    map[nb_lines] = NULL;

    fclose(file);
    return map;
}

static char **init_default_map(void)
{
    char **map = malloc(sizeof(char *) * (DEFAULT_WIDTH + 1));

    if (map == NULL)
        return NULL;

    // Init each array of map
    for (int i = 0; i < DEFAULT_WIDTH; i++) {
        map[i] = malloc(sizeof(char) * (DEFAULT_LENGHT + 1));

        // Check for each array allocation and free whats been already malloc'd
        if (map[i] == NULL) {
            for (int j = 0; j <= i; j++)
                free(map[j]);
            free(map);
            return NULL;
        }

        // Init array with '.' filled string
        for (int index = 0; index < DEFAULT_LENGHT; index++)
            map[i][index] = '.';
        map[i][DEFAULT_LENGHT] = '\0';
    }
    map[DEFAULT_WIDTH] = NULL;
    return map;
}

char **parse_arg(int ac, char *argv[])
{
    char **map = NULL;

    if (ac == 1) {
        map = init_default_map();
        if (map == NULL) {fprintf(stderr, "Malloc has faild\n"); return NULL;}
    } else if (ac == 2) {
        map = map_from_file(argv[1]);
        if (map == NULL) return NULL;
    } else {
        fprintf(stderr, "Wrong number of argument, expected only 2");
        return NULL;
    }
    for (int i = 0; map[i] != NULL; i++) {
        printw(map[i]);
    }
    refresh();
    getch();
    return map;
}
