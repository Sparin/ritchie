#include <stdio.h>
#define MAXLINE 20

int _getline(char line[], int lim);
void copy(char to[], char from[]);

int main(void)
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = _getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("%s", longest);
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

void copy(char to[], char from[])
{
    int i;
    i = 0;

    while (i < MAXLINE && (to[i] = from[i]) != '\0')
        ++i;
}