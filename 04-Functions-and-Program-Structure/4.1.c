#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int strrindex(char *string, char *pattern);

void main()
{
    char text[] = "Let's get some text. Awesome of awesome. Cringe to cringe";
    char pattern[] = "some";

    printf("strrindex(char *, char *) returned '%i'", strrindex(text,pattern));
}

int strrindex(char *string, char *pattern)
{
    int patternLength = strlen(pattern);
    int stringLength = strlen(string);

    int patternPosition = patternLength - 1;

    for (int i = stringLength - 1; i > 0; i--)
    {
        if (pattern[patternPosition] == string[i])
        {
            patternPosition--;
            if (patternPosition < 0)
                return i;
        }
        else
            patternPosition = patternLength - 1;
    }

    return -1;
}