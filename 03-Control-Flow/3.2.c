#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 500
#define MAX_LENGTH MAX_INPUT_LENGTH * 2

void escape(char *s, char *t);
void unescape(char *s, char *t);

void main()
{
    char *input = malloc((MAX_INPUT_LENGTH + 1) * sizeof(char));
    char *result = malloc((MAX_LENGTH + 1) * sizeof(char));

    fgets(input, MAX_INPUT_LENGTH + 1, stdin);

    escape(input, result);
    printf("Escaped straing: '%s'\n", result);
    
    unescape(input, result);
    printf("Unescaped string: '%s'\n", result);
}

void escape(char *s, char *t)
{
    int tPtr = 0;
    for (int sPtr = 0; s[sPtr] != '\0'; s++)
    {
        switch (s[sPtr])
        {
        case '\n':
            t[tPtr++] = '\\';
            t[tPtr++] = 'n';
            break;

        case '\t':
            t[tPtr++] = '\\';
            t[tPtr++] = 't';
            break;

        default:
            t[tPtr++] = s[sPtr];
            break;
        }
    }
    t[tPtr] = '\0';
}

void unescape(char *s, char *t)
{
    int tPtr = 0;
    for (int sPtr = 0; s[sPtr] != '\0'; s++)
    {
        switch (s[sPtr])
        {
        case '\\':
            switch (s[++sPtr])
            {
            case 't':
                t[tPtr++] = '\t';
                break;

            case 'n':
                t[tPtr++] = '\n';
                break;

            default:
                t[tPtr++] = '\\';
                t[tPtr++] = s[sPtr];
                break;
            }
            break;

        default:
            t[tPtr++] = s[sPtr];
            break;
        }
    }
    t[tPtr] = '\0';
}
