#include <stdio.h>

int main()
{
    int lastCharacter = 0;

    while ((lastCharacter = getchar()) != EOF)
    {
        switch (lastCharacter)
        {
        case '\t':
            putchar('\\');
            putchar('t');
            break;

        case '\b':
            putchar('\\');
            putchar('b');
            break;

        case '\\':
            putchar('\\');
            putchar('\\');
            break;

        default:
            putchar(lastCharacter);
        }
    }
}