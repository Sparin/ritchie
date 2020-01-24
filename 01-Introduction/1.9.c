#include <stdio.h>

// Or include stdbool.h instead of
#define true 1
#define false 0
#define bool int

// #include "stdbool.h" // C99 ANSI standard

int main()
{
    int lastCharacter = 0;
    bool previousCharacterIsBlank = false;

    while ((lastCharacter = getchar()) != EOF)
    {
        if (lastCharacter == ' ')
        {
            if (!previousCharacterIsBlank)
                putchar(lastCharacter);
        }
        else
            putchar(lastCharacter);

        previousCharacterIsBlank = lastCharacter == ' ';
    }
}