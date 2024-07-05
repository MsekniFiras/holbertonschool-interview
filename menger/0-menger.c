#include <stdio.h>
#include <math.h>

void menger(int level);

/**
 * menger - Draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
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
