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
/*  PLEASE CHECK THIS CODE ONLY AFTER VALIDATION OF THE EXERCISE                */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv)
{
    int number;
    int guess;
    int attempts;

    if (argc > 2)
        return (-1);
    
    srand(argc == 2 ? strtoul(argv[1], &argv[1], 10) : (unsigned)time(NULL));
    number = rand() % 100 + 1;
    attempts = 0;
    while (1)
    {
        printf("Guess the number : ");
        if (scanf("%d", &guess) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("Please enter a valid integer\n");
            continue;
        }
        if (guess < 1 || guess > 100)
        {
            printf("Please enter a valid integer\n");
            continue;
        }
        attempts++;
        if (guess > number)
        {
            printf("Number to find is lower than %d\n", guess);
        }
        else if (guess < number)
        {
            printf("Number to find is greater than %d\n", guess);
        }
        else
        {
            printf("Congratulation ! You find the number %d in %d attempts\n", guess, attempts);
            return (0);
        }
    }

    return (0);
}