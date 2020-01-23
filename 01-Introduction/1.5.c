#include "stdio.h"

main()
{
    printf("-={ Celsius vs Fahrenheit }=-\n");
    for (float i = 300; i >= 0; i -= 20)
        printf("%3.0f %6.1f\n", i, i * 9.0 / 5.0 + 32.0);
}