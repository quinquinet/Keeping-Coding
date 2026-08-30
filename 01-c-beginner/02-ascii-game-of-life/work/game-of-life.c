/*    ___  __    _______   _______   ________  ___  ________   ________         */
/*    |\  \|\  \ |\  ___ \ |\  ___ \ |\   __  \|\  \|\   ___  \|\   ____\       */
/*    \ \  \/  /|\ \   __/|\ \   __/|\ \  \|\  \ \  \ \  \\ \  \ \  \___|       */
/*     \ \   ___  \ \  \_|/_\ \  \_|/_\ \   ____\ \  \ \  \\ \  \ \  \  ___     */
/*      \ \  \\ \  \ \  \_|\ \ \  \_|\ \ \  \___|\ \  \ \  \\ \  \ \  \|\  \    */
/*       \ \__\\ \__\ \_______\ \_______\ \__\    \ \__\ \__\\ \__\ \_______\   */
/*        \|__| \|__|\|_______|\|_______|\|__|     \|__|\|__| \|__|\|_______|   */
/*                                                                              */
/*     ________  ________  ________  ___  ________   ________                   */
/*    |\   ____\|\   __  \|\   ___ \|\  \|\   ___  \|\   ____\                  */
/*    \ \  \___|\ \  \|\  \ \  \_|\ \ \  \ \  \\ \  \ \  \___|                  */
/*     \ \  \    \ \  \\\  \ \  \ \\ \ \  \ \  \\ \  \ \  \  ___                */
/*      \ \  \____\ \  \\\  \ \  \_\\ \ \  \ \  \\ \  \ \  \|\  \               */
/*       \ \_______\ \_______\ \_______\ \__\ \__\\ \__\ \_______\              */
/*        \|_______|\|_______|\|_______|\|__|\|__| \|__|\|_______|              */
/*______________________________________________________________________________*/
/*  THIS CODE MAY CONTAIN MISTAKES, PLEASE TELL IF YOU FIND ANY                 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

#define INVALID_FILE_INPUT -1

typedef bool** Grid;

Grid    create_grid(void)
{
    Grid    grid;
    int     i;
    int     j;

    grid = malloc(sizeof(bool *) * HEIGHT);
    i = 0;
    while (i < HEIGHT)
    {
        grid[i] = malloc(sizeof(bool) * WIDTH);
        j = 0;
        while (j < WIDTH)
        {
            grid[i][j] = false;
            j++;
        }
        i++;
    }
    return (grid);
}

void    free_grid(Grid *grid)
{
    int i;

    i = 0;
    while (i < HEIGHT)
    {
        free((*grid)[i]);
        i++;
    }
    free(*grid);
}

int    read_grid(Grid *grid, char *path)
{
    int     fd;
    char    buffer[2048];
    int     bytes_read;
    int     i;
    int     j;
    char    *line;

    i = 0;
    fd = open(path, O_RDONLY);

    if (fd < 0)
        return -1;

    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    close(fd);

    if (bytes_read <= 0 || bytes_read != (WIDTH + 1) * HEIGHT - 1)
        return INVALID_FILE_INPUT;

    buffer[bytes_read] = '\0';
    line = strtok(buffer, "\n");
    
    while (line != NULL)
    {
        if (strlen(line) != WIDTH)
            return INVALID_FILE_INPUT;
        j = 0;
        while (j < WIDTH)
        {
            if (line[j] != '.' && line[j] != '#')
                return INVALID_FILE_INPUT;
            (*grid)[i][j] = line[j] == '#';
            j++;
        }
        line = strtok(NULL, "\n");
        i++;
    }

    return 0;
}

void    soup(Grid *grid)
{
    int i;
    int j;

    srand((unsigned)time(NULL));
    i = 0;
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            (*grid)[i][j] = (rand() % 2 == 0) ? true : false;
            j++;
        }
        i++;
    }
}

int count_neighbors(Grid grid, int x, int y)
{
    int count;
    int i;
    int j;
    int nx;
    int ny;

    count = 0;
    i = -1;
    while (i <= 1)
    {
        j = -1;
        while (j <= 1)
        {
            if (i == 0 && j == 0)
            {
                j++;
                continue ;
            }
            nx = x + j;
            ny = y + i;
            if (ny < 0) ny = HEIGHT - 1;
            if (nx < 0) nx = WIDTH - 1;
            if (ny >= HEIGHT) ny = 0;
            if (nx >= WIDTH) nx = 0;
            if (grid[ny][nx]) count++;
            j++;
        }
        i++;
    }
    return (count);
}

void    update(Grid *grid)
{
    Grid    new_grid;
    int     i;
    int     j;
    int     neighbors;

    new_grid = create_grid();
    i = 0;
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            neighbors = count_neighbors(*grid, j, i);
            if ((*grid)[i][j])
            {
                if (neighbors == 2 || neighbors == 3)
                    new_grid[i][j] = true;
            }
            else
            {
                if (neighbors == 3)
                    new_grid[i][j] = true;
            }
            j++;
        }
        i++;
    }
    free_grid(grid);
    *grid = new_grid;
}

void    draw(Grid *grid)
{
    int i;
    int j;

    i = 0;
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            if ((*grid)[i][j])
                printf("#");
            else
                printf(".");
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    Grid    grid;
    int     generation;

    if (argc < 2 || argc > 3)
        return (-1);

    grid = create_grid();
    generation = atoi(argv[1]);

    if (generation < 0)
    {
        printf("Invalid generations number");
        return (-1);
    }

    if (argc == 3)
    {
        if (read_grid(&grid, argv[2]) == INVALID_FILE_INPUT)
        {
            printf("Invalid file input");
            return (-1);
        }
    }
    else
        soup(&grid);

    while (generation)
    {
        update(&grid);
        draw(&grid);
        generation--;
    }

    return (0);
}