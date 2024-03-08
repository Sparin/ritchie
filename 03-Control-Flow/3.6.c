#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 500
#define MAX_LENGTH MAX_INPUT_LENGTH * 2

int itob(int number, char *string, int base, int minWidth);
char itoh(int number);
void reverse(char *string);

int main()
{
    char *string = malloc(MAX_LENGTH + 1 * sizeof(char));

    int number = -32760;
    int base = 2;
    int minWidth = 32;
    int result = itob(number, string, base, minWidth);

    if (result == 0)
        printf("%s with base %i\n", string, base);
    else
        printf("itob(int, char *, int) returned %i\n", result);

    return result;
}

int itob(int number, char *string, int base, int minWidth)
{
    if (base > 16 || base < 2)
        return -1;

    int i = 0;
    bool isNegativeNumber = number < 0;

    while ((number / base) + (number % base) != 0)
    {
        string[i++] = isNegativeNumber
                          ? itoh(-(number % base))
                          : itoh(number % base);
        number /= base;
    }

    while (i < minWidth)
        string[i++] = '0';

    string[i++] = 'x';
    string[i++] = '0';

    if (isNegativeNumber)
        string[i++] = '-';

    string[i] = '\0';
    reverse(string);
    return 0;
}

char itoh(int number)
{
    if (number >= 10)
        return number % 10 + 'A';
    return number + '0';
}

void reverse(char *string)
{
    int i, j;
    char c;

    for (i = 0, j = strlen(string) - 1; i < j; i++, j--)
    {
        c = string[i];
        string[i] = string[j];
        string[j] = c;
    }
}