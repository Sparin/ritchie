#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 500
#define MAX_LENGTH MAX_INPUT_LENGTH * 2

void expand(char *s1, char *s2);

main(int argc, char const *argv[])
{
    char *input = malloc((MAX_INPUT_LENGTH + 1) * sizeof(char));
    char *result = malloc((MAX_LENGTH + 1) * sizeof(char));

    fgets(input, MAX_INPUT_LENGTH + 1, stdin);

    expand(input, result);

    printf("expand(char *, char *): '%s'", result);
}

void expand(char *s1, char *s2)
{
    int s2Ptr = 0;
    char currentCharacter = 0;
    char previousCharacter = 0;
    for (int s1Ptr = 0; s1[s1Ptr] != '\0'; s1Ptr++)
    {
        currentCharacter = s1[s1Ptr];

        bool isRangeFound = currentCharacter == '-' && previousCharacter != 0 && s1[s1Ptr + 1] != '\0';
        if (isRangeFound)
        {
            char start = previousCharacter + 1;
            char end = s1[++s1Ptr];

            while (start <= end)
                s2[s2Ptr++] = start++;

            currentCharacter = s1[s1Ptr];
            previousCharacter = s1[s1Ptr - 1];
        }
        else
            s2[s2Ptr++] = currentCharacter;

        previousCharacter = currentCharacter;
    }

    s2[s2Ptr++] = '\0';
}