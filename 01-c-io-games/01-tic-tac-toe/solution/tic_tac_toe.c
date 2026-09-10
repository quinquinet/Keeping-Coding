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
#include <string.h>

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
    bool    firstTry;
    char    x_char;
    char    y_char;
    int     next;
    int     input_count;

    grid = create_grid();
    player = 'X';
    firstTry = true;
    while(1)
    {
        if (firstTry)
            printf("Player %c, your move : ", player);

        input_count = scanf(" %c%c", &x_char, &y_char);
        next = getchar();
        if (input_count != 2 ||
            x_char < '1' || x_char > '3' ||
            y_char < '1' || y_char > '3' ||
            (next != '\n' && next != EOF))
        {
            while (next != '\n' && next != EOF)
                next = getchar();
            firstTry = false;
            printf("Invalid input, try again : ");
            continue;
        }

        x = x_char - '0';
        y = y_char - '0';

        if (x < 1 || x > 3 || y < 1 || y > 3)
        {
            firstTry = false;
            printf("Invalid input, try again : ");
            continue;
        }

        if (grid[x - 1][y - 1] == ' ')
        {
            firstTry = true;
            grid[x - 1][y - 1] = player;
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
            firstTry = false;
            printf("Cell already taken, try again : ");
            continue;
        }
    }
    free_grid(&grid);
    return (0);
}