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

int count_words(char *str, char delim)
{
    int c;
    int inword;

    c = 0;
    inword = 0;
    while (*str)
    {
        if (*str == delim)
        {
            if (inword)
            {
                inword = 0;
                c++;
            }
        }
        else
        {
            inword = 1;
        }
        str++;        
    }
    if (inword)
        c++;
    return (c);
}

char **ft_split(char *str, char delim)
{
    int     i;
    int     j;
    int     len;
    int     count;
    char    **out;
    char    *start;
    int     inword;

    i = 0;
    j = 0;
    len = 0;
    start = str;
    inword = 0;
    count = count_words(str, delim);
    out = (char **)malloc((count + 1) * sizeof(char *));
    if (!out)
        return (NULL);

    while (*str)
    {
        if (*str == delim)
        {
            if (inword)
            {
                inword = 0;
                len = str - start;
                out[i] = (char *)malloc((len + 1) * sizeof(char));
                j = 0;
                while (j < len)
                {
                    out[i][j] = start[j];
                    j++;
                }
                out[i][j] = '\0';
                i++;
            }
        }
        else
        {
            if (!inword)
                start = str;
            inword = 1;
        }
        str++;
    }

    if (inword)
    {
        len = str - start;
        out[i] = (char *)malloc((len + 1) * sizeof(char));
        j = 0;
        while (j < len)
        {
            out[i][j] = start[j];
            j++;
        }
        out[i][j] = '\0';
        i++;
    }

    out[i] = NULL;
    return (out);
}