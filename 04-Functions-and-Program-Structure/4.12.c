#include <stdbool.h>
#include <stdlib.h>

void itoa_task(char *, int);
void reverse(char s[]);

void main(int argc, char const *argv[])
{
    char result[500];
    int n = INT_MAX;

    itoa_task(result, n, true);

    printf("%s", result);
}

// I were sleepy and I don't care actually about code quality here 
void itoa_task(char *string, int value, bool doReverse)
{
    bool isNegativeNumber = value < 0;

    if ((value / 10) + (value % 10) != 0)
    {
        string[0] = isNegativeNumber
                        ? -(value % 10) + '0'
                        : value % 10 + '0';
        if (value / 10 == 0 && isNegativeNumber)
        {
            string[1] = '-';
            itoa_task(string + 2, value / 10, false);
        }
        else
            itoa_task(string + 1, value / 10, false);
    }
    else
    {
        string[0] = '\0';
    }
    if (doReverse)
        reverse(string);
}

void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}