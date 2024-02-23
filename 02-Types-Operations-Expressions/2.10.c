#include <stdio.h>

int main(int argc, char const *argv[])
{
    char character = 0;
    while ((character = getchar()) != EOF)
    {
        character = character >= 'A' && character <= 'Z' ? character - 'A' + 'a' : character;
        putchar(character);
    }

    return 0;
}
