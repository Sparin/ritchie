#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int lim);
void copy(char to[], char from[]);

int main(void)
{
    int len, max;
    char line[MAXLINE];

    while ((len = _getline(line, MAXLINE)) >= 0)
    {
        len = trim(line, len);
        if (len > 1)
            printf("%s\n", line);
    }
}

int _getline(char line[], int lim)
{
    int length;
    int character;

    for (length = 0; length < lim - 1 && (character = getchar()) != EOF && character != '\n'; length++)
        line[length] = character;

    if (character == EOF && length == 0)
        return -1;

    if (length < lim - 1)
        line[length++] = '\0';
    else
        line[lim - 1] = '\0';

    return length;
}

int trim(char line[], int length)
{
    length -= 2;
    while (line[length] == '\t' || line[length] == ' ' || line[length] == '\r')
    {
        line[length] = '\0';
        length--;
    }
    return length + 2;
}

void reverse(char line[], int length)
{
    // Do not reverse null terminate character
    length--;
    char temp = 0;
    for (int i = 0; i < length / 2; i++)
    {
        temp = line[i];
        line[i] = line[length - 1 - i];
        line[length - 1 - i] = temp;
    }
}