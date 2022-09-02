#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int lim);
void copy(char to[], char from[]);

int main(void)
{
    int len, max;
    char line[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0)
    {
        if (len > 80)
            printf("%s\n", line);
    }
}

int _getline(char line[], int lim)
{
    int length;
    int character;

    for (length = 0; (character = getchar()) != EOF && character != '\n'; length++)
        if (length < lim - 1)
            line[length] = character;

    if (length < lim - 1)
        line[length] = '\0';
    else
        line[lim - 1] = '\0';

    return length;
}