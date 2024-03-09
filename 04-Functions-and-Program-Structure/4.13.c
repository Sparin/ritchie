#include <stdbool.h>
#include <stdlib.h>

void itoa_task(char *, int);
void reverse(char *string, int length);
void swap(char *left, char *right);

void main(int argc, char const *argv[])
{
    char result[500];
    int n = INT_MIN;

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
        reverse(string, strlen(string));
}

void reverse(char *string, int length)
{
    if (length < 2)
        return;

    swap(string, string + length - 1);
    reverse(string + 1, length - 2);
}

void swap(char *left, char *right)
{
    char temp = *left;
    *left = *right;
    *right = temp;
}