#include "stdio.h"

float convertToFahrenheit(float celsius);

main()
{
    float celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("-={ Celsius vs Fahrenheit }=-\n");
    while (celsius <= upper)
    {
        printf("%3.0f %6.1f\n", celsius, convertToFahrenheit(celsius));
        celsius += step;
    }
}

float convertToFahrenheit(float celsius){
    return celsius * 9.0 / 5.0 + 32.0;
}