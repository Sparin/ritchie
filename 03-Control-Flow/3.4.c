#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void reverse(char s[]);
void task_itoa(int n, char s[]);

void main()
{
    char result[500];
    int n = INT_MIN;

    task_itoa(n, result);

    printf("%s", result);
}

void task_itoa(int n, char s[])
{
    int i = 0;
    bool isNegativeNumber = n < 0;

    while ((n / 10) + (n % 10) != 0)
    {
        s[i++] = isNegativeNumber
                     ? -(n % 10) + '0'
                     : n % 10 + '0';
        n /= 10;
    }

    if (isNegativeNumber)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
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