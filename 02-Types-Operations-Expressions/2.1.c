#include <limits.h>
#include <float.h>
#include <stdio.h>

int main()
{
    printf("%+15s: from %+13d\tto %+13d\n", "char", CHAR_MIN, CHAR_MAX);
    printf("%+15s: from %+13d\tto %+13d\n", "signed char", SCHAR_MIN, SCHAR_MAX);
    printf("%+15s: from %+13d\tto %+13d\n", "unsigned char", 0, UCHAR_MAX);

    printf("%+15s: from %+13d\tto %+13d\n", "short", SHRT_MIN, SHRT_MAX);
    printf("%+15s: from %+13d\tto %+13d\n", "unsigned short", 0, USHRT_MAX);

    printf("%+15s: from %+13d\tto %+13d\n", "int", INT_MIN, INT_MAX);
    printf("%+15s: from %+20d\tto %+20llu\n", "unsigned int", 0, UINT_MAX);

    printf("%+15s: from %+20lld\tto %+20lld\n", "long", LONG_MIN, LONG_MAX);
    printf("%+15s: from %+20llu\tto %+20llu\n", "unsigned long", 0, ULONG_MAX);
}