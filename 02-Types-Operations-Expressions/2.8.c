#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int x, n;
    scanf("%i %i", &x, &n);
    int result = rightrot(x, n);
    printf("%i", result);
    return 0;
}

rightrot(unsigned int x, unsigned int n)
{
    while (n > 0)
    {
        if (x & 1)
            x = (x >> 1) | ~(~0U >> 1);
        else
            x = (x >> 1);
        n--;
    }

    return x;
}
