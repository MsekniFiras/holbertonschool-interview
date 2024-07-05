#include <stdio.h>
#include <math.h>

/**
 * menger - Draws a 2D Menger Sponge of a given level.
 * @level: the level of the Menger Sponge to draw
 *
 * Description: This function prints a 2D representation of a Menger Sponge
 *              using '#' and ' ' characters based on the specified level.
 */
void menger(int level)
{
    int size, i, j, k, l;
    char symbol;

        if (level < 0)
        return;

    size = pow(3, level);

    for (i = 0; i < size; i++)
        {
    for (j = 0; j < size; j++)
        {
    symbol = '#';
    k = i;
    l = j;
            while (k > 0 || l > 0)
           {
            if (k % 3 == 1 && l % 3 == 1)
               {
                symbol = ' ';
                    break;
                }
                k /= 3;
                l /= 3;
            }
            printf("%c", symbol);
        }
        printf("\n");
    }
}
