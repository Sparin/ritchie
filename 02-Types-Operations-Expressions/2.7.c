#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int x, p, n;
    scanf("%i %i %i", &x, &p, &n);
    int result = invert(x, p, n);
    printf("%i", result);
    return 0;
}

invert(unsigned int x, unsigned int p, unsigned int n)
{
    for (int i = 0; i < 32; i++)
    {
        if (i <= 31 - p && i > 31 - (p + n))
        {
            if (x & 1)
                x = (x >> 1);
            else
                x = (x >> 1) | ~(~0U >> 1);
        }
        else
        {
            if (x & 1)
                x = (x >> 1) | ~(~0U >> 1);
            else
                x = (x >> 1);
        }
    }

    return x;
}
