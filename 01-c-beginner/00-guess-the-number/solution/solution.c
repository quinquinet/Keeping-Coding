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
/*  THIS CODE MAY CONTAIN MISTAKES                                              */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    int number;
    int guess;
    int attempts;

    srand((unsigned)time(NULL));
    number = rand() % 100 + 1;  // Generate a random number between 1 and 100
    attempts = 5;
    while (attempts > 0)
    {
        printf("Guess the number : ");
        if (scanf("%d", &guess) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("Please enter a valid integer.\n");
            continue;
        }
        if (guess < 1 || guess > 100)
        {
            printf("Invalid guess, please try again.\n");
            continue;
        }
        if (guess > number)
        {
            printf("Number to find is lower than %d.\n", guess);
        }
        else if (guess < number)
        {
            printf("Number to find is greater than %d.\n", guess);
        }
        else
        {
            printf("Congratulation ! You find the number %d in %d attempts.\n", guess, 6 - attempts);
            return (0);
        }
        attempts--;
    }
    printf("Game over. The number was %d.\n", number);

    return (0);
}