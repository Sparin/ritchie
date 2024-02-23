#include <stdio.h>

int main(int argc, char const *argv[])
{
    int result = setbits(12, 30, 2, 3); // 15
    printf("%i\n", result);

    result = setbits(48, 28, 2, 2); // 56
    printf("%i\n", result);

    result = setbits(-252706816, 4, 4, 15); // -1 048 576
    printf("%i\n", result);

    result = setbits(0, 0, 4, 7); // 1 879 048 192
    printf("%i\n", result);

    return 0;
}

int setbits(int x, int p, int n, int y)
{
    unsigned int mask = 0xFFFFFFFF >> (32 - n);
    int bits = y & mask;

    int result = x;
    // preserve left side of x
    result >>= (32 - p);
    // add n zeroes
    result <<= n;
    // apply n bits of y
    result |= bits;

    result <<= (32 - p - n);
    int rightBitsShift = p + n == 32 ? 0 : p + n;
    mask = 0xFFFFFFFF >> rightBitsShift;
    result |= (mask & x);

    return result;
}