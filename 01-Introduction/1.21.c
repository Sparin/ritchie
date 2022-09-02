#include <stdio.h>

int n = 4;

int main(void)
{
    char character;
    int spaceCounter = 0;

    while ((character = getchar()) != EOF)
    {
        if (character == ' ')
            spaceCounter++;
        else
        {
            for (int i = 0; i < spaceCounter; i++)
                putchar(' ');
            spaceCounter = 0;
            putchar(character);
        }

        if (spaceCounter == n)
        {
            putchar('\t');
            spaceCounter = 0;
        }
    }
}
