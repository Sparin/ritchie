#include <stdio.h>

int n = 4;

int main(void)
{
    char character;

    while ((character = getchar()) != EOF)
        if (character == '\t')
            for (int i = 0; i < n; i++)
                putchar(' ');
        else
            putchar(character);
}
