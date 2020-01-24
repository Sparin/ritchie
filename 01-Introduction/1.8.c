#include <stdio.h>

int main()
{
    int toCountCharacter = ' '; // place countable character here: \n, \t or ' ' 
    int counter = 0;
    int currentCharacter = 0;

    while ((currentCharacter = getchar()) != EOF)
        if (currentCharacter == toCountCharacter)
            ++counter;
            
    printf("%d", counter);
}