#include <stdio.h>

void squeeze(char s1[], char s2[]);
int any(char s1, char s2[]);

int main(int argc, char const *argv[])
{
    char s1[5000];
    char s2[5000];
    scanf("%s %s", &s1, &s2);
    squeeze(s1, s2);
    printf("%s", s1);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int j = 0;
    for (int i = 0; s1[i] != '\0'; i++)
        if (any(s1[i], s2) == -1)
            s1[j++] = s1[i];
    s1[j] = '\0';
}

int any(char s1, char s2[])
{
    for (int j = 0; j < s2[j] != '\0'; j++)
        if (s1 == s2[j])
            return j;

    return -1;
}