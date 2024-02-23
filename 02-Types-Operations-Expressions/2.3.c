#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buffer[1000];
    scanf("%s", &buffer);

    int result = htoi(buffer);

    printf("%i", result);
    return 0;
}

int htoi(char hexNumber[])
{
    int length = strlen(hexNumber);
    int result = 0;
    int i = 0;

    if (hexNumber[0] == '0' && (hexNumber[1] == 'x' || hexNumber[1] == 'X'))
        i = 2;

    if (length <= 0 + i || length > 4 + i)
        return -1;

    for (; i < length; i++)
    {
        result = result << 4;
        char character = hexNumber[i];

        if (character >= 'A' && character <= 'F')
            result |= character - 'A' + 10;
        else if (character >= 'a' && character <= 'f')
            result |= character - 'a' + 10;
        else if (character >= '0' && character <= '9')
            result |= character - '0';
        else
            return -1;
    }

    return result;
}