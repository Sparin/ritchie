#include <stdio.h>

#define swap(t, x, y) \
    {                 \
        t temp = x;   \
        x = y;        \
        y = temp;     \
    }

int main(int argc, char const *argv[])
{
    char a = 'a';
    char z = 'z';
    swap(char, a, z);

    putchar(a);
    putchar(z);
}
