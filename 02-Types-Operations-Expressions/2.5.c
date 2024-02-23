#include <stdio.h>

int any(char s1[], char s2[]);

int main(int argc, char const *argv[])
{
    char s1[5000];
    char s2[5000];
    scanf("%s %s", &s1, &s2);
    int result = any(s1, s2);
    printf("%i", result);
    return 0;
}

int any(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++)
        for (int j = 0; j < s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;

    return -1;
}