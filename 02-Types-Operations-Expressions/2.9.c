#include <stdio.h>

int main()
{
    printf("%i\n", bitcount(1024 - 1));
    return 0;
}

int bitcount(unsigned int x)
{
    int result = 0;
    for (; x != 0; x &= (x - 1))
        result++;
    return result;
}