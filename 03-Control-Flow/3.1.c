#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE INT_MAX / 16

void benchmark(int x, int *array, int n);
void initArray(int *v, int n);

int main(int argc, char const *argv[])
{
    int *array = malloc(ARRAY_SIZE * sizeof(int));

    initArray(array, ARRAY_SIZE);

    benchmark(1, array, ARRAY_SIZE);

    return 0;
}

void benchmark(int x, int *array, int n)
{
    clock_t start, end;
    double duration;

    start = clock();
    for (int i = 0; i < n; i++)
        binsearch(x, array, n);
    end = clock();

    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("binsearch(int, int[], int) executed in %2.3f seconds\n", duration);

    start = clock();
    for (int i = 0; i < n; i++)
        binsearch_original(x, array, n);
    end = clock();

    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("binsearch_original(int, int[], int) executed in %2.3f seconds\n", duration);
}

void initArray(int *v, int n)
{
    for (int i = 0; i < n; ++i)
        v[i] = i;
}

int binsearch(int x, int *v, int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (v[mid] == n)
        return mid;
    return -1;
}

int binsearch_original(int x, int *v, int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}
