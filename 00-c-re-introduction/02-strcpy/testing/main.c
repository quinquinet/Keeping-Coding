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

#include <string.h>
#include <stdlib.h>

char *ft_strcpy(char *dest, char *src);

int main(int ac, char** av)
{
    if (ac != 2)
        return (-1);

    char *src = av[1];
    char *ft_dest = malloc(strlen(src) + 1);
    char *real_dest = malloc(strlen(src) + 1);

    if (!ft_dest || !real_dest)
        return (-1);

    char *ft_result = ft_strcpy(ft_dest, src);
    char *real_result = strcpy(real_dest, src);

    int ret = strcmp(ft_result, real_result);

    free(ft_dest);
    free(real_dest);

    return (ret);
}