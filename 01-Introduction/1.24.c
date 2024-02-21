#include <stdio.h>
#include "stdbool.h"
#define STACK_LIMIT 50000

// I were lazy to refactor this. Don't judge hard
int main()
{
    char stack[STACK_LIMIT];
    int pointer = 0;
    // to handle "\'" cases
    char buffer[2];

    while ((buffer[1] = getchar()) != EOF)
    {
        bool isOutOfRange = pointer - 1 < 0;
        bool isString = !isOutOfRange && (stack[pointer - 1] == '\'' || stack[pointer - 1] == '\"');
        switch (buffer[1])
        {
        case '[':
        case '{':
        case '(':
            if (isString)
                break;
            stack[pointer++] = buffer[1];
            break;

        case '\'':
            if (buffer[0] == '\\')
                break;
            if (!isOutOfRange && stack[pointer - 1] == '\'')
                pointer--;
            else
                stack[pointer++] = buffer[1];
            break;

        case '\"':
            if (buffer[0] == '\\')
                break;
            if (!isOutOfRange && stack[pointer - 1] == '\"')
                pointer--;
            else
                stack[pointer++] = buffer[1];
            break;

        case ']':
            if (isString)
                break;
            if (isOutOfRange && stack[pointer - 1] != '[')
            {
                printf("Bruh");
                return -1;
            }
            pointer--;
            break;

        case '}':
            if (isString)
                break;
            if (isOutOfRange && stack[pointer - 1] != '{')
            {
                printf("Bruh");
                return -1;
            }
            pointer--;
            break;

        case ')':
            if (isString)
                break;
            if (isOutOfRange && stack[pointer - 1] != '(')
            {
                printf("Bruh");
                return -1;
            }
            pointer--;
            break;
        }

        buffer[0] = buffer[1];
    }

    if (pointer != 0)
    {
        printf("Bruh");
        return -1;
    }
    else
        printf("Good boy");
}