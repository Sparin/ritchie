#include <stdio.h>
#define lim 500

int main()
{
    char s[lim];
    char c;
    for (int i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;

    for (int i = 0; i < lim - 1; ++i)
    {
        c = getchar();
        if (c == '\n')
            break;
        if (c == EOF)
            break;
    }
}
