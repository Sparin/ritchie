#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

double atof(char *string);

void main()
{
    char payload[5][500] = {
        "314e-2",
        "   12.0e1",
        "  13.37",
        "1337",
        "133.7E-5"};

    for (int i = 0; i < 5; i++)
        printf("atof(%s) returned '%lf'\n", payload[i], atof(payload[i]));
}

double atof(char *string)
{
    double value, power;
    bool isPositiveNumber = false;
    int i = 0;

    for (i = 0; isspace(string[i]); i++)
        ;
    isPositiveNumber = string[i] != '-';

    if (string[i] == '-' || string[i] == '+')
        i++;

    for (value = 0.0; isdigit(string[i]); i++)
        value = 10.0 * value + (string[i] - '0');

    if (string[i] == '.')
        i++;

    for (power = 1.0; isdigit(string[i]); i++)
    {
        value = 10.0 * value + (string[i] - '0');
        power *= 10;
    }

    if (string[i] == 'e' || string[i] == 'E')
    {
        i++;
        bool isPositiveExponent = string[i] != '-';
        if (string[i] == '-' || string[i] == '+')
            i++;

        int j;
        char exponentString[21];
        for (j = 0; isdigit(string[i]) && j < 20; j++)
            exponentString[j] = string[i++];
        exponentString[j] = '\0';
        int exponent = atoi(exponentString);

        while (exponent-- > 0)
            power = isPositiveExponent
                        ? power / 10
                        : power * 10;
    }

    return (isPositiveNumber ? 1.0 : -1.0) * value / power;
}