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
/*  PLEASE CHECK THIS CODE ONLY AFTER VALIDATION OF THE EXERCISE                */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef char** Grid;

Grid create_grid(void)
{
    Grid    grid;
    int     i;
    int     j;

    grid = malloc(3 * sizeof(char *));
    i = 0;
    while (i < 3)
    {
        grid[i] = malloc(sizeof(char) * 3);
        j = 0;
        while (j < 3)
        {
            grid[i][j] = ' ';
            j++;
        }
        i++;
    }
    return (grid);
}

void free_grid(Grid *grid)
{
    int     i;

    i = 0;
    while(i < 3)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}

bool check_win(Grid *grid)
{
    int    i;

    i = 0;
    while (i < 3)
    {
        if (((*grid)[i][0] == (*grid)[i][1] && (*grid)[i][0] == (*grid)[i][2]) && (*grid)[i][0] != ' ')
            return (true);
        if (((*grid)[0][i] == (*grid)[1][i] && (*grid)[0][i] == (*grid)[2][i]) && (*grid)[0][i] != ' ')
            return (true);
        i++;
    }
    if (((*grid)[0][0] == (*grid)[1][1] && (*grid)[0][0] == (*grid)[2][2]) && (*grid)[0][0] != ' ')
        return (true);
    if (((*grid)[2][0] == (*grid)[1][1] && (*grid)[2][0] == (*grid)[0][2]) && (*grid)[1][1] != ' ')
        return (true);

    return (false);
}

void draw(Grid *grid)
{
    int     i;
    int     j;
    char    tiles[] = " | | \n-+-+-\n | | \n-+-+-\n | | \n";

    i = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            tiles[(i * 12) + (j * 2)] = (*grid)[i][j];
            j++;
        }
        printf("\n");
        i++;
    }
    printf("%s", tiles);
}

int main(void)
{
    Grid    grid;
    int     x;
    int     y;
    char    player;

    grid = create_grid();
    player = 'X';
    while(1)
    {
        printf("Input: ");
        if (scanf("%d %d", &x, &y) != 2)
        {
            printf("Please enter a valid integer.\n");
            continue;
        }
        if (x < 0 || x > 2 || y < 0 || y > 2)
        {
            printf("Invalid inputs.");
            continue;
        }
        if (grid[y][x] == ' ')
        {
            printf("Valid inputs.\n");
            grid[y][x] = player;
            draw(&grid);
            if (check_win(&grid))
            {
                printf("Player %c won !", player);
                break;
            }
            player = player == 'X' ? 'O' : 'X';
        }
        else
        {
            printf("Cell already fill.");
            continue;
        }
    }
    free_grid(&grid);
    return (0);
}