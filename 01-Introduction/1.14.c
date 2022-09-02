#include <stdio.h>

// Or include stdbool.h instead of
#define true 1
#define false 0
#define bool int

#define MAX_VARIOUS_CHARACTERS 100

int main()
{
    bool isAwaitingNewWord = false;
    int counter = 0;

    int characterCounter[MAX_VARIOUS_CHARACTERS];
    int characterDefinitions[MAX_VARIOUS_CHARACTERS];

    for (int i = 0; i < MAX_VARIOUS_CHARACTERS; i++)
    {
        characterCounter[i] = 0;
        characterDefinitions[i] = 0;
    }

    int lastFreeIndex = 0;
    int character;
    while ((character = getchar()) != EOF)
    {
        int characterIndex = -1;
        for (int i = 0; i < lastFreeIndex; i++)
            if (characterDefinitions[i] == character)
                characterIndex = i;

        if (characterIndex != -1)
        {
            characterCounter[characterIndex]++;
        }
        else if (lastFreeIndex < MAX_VARIOUS_CHARACTERS)
        {
            characterDefinitions[lastFreeIndex] = character;
            characterCounter[lastFreeIndex]++;
            lastFreeIndex++;
        }
    }

    int max = getMax(characterCounter, MAX_VARIOUS_CHARACTERS);

    for (int i = 0; i < lastFreeIndex; i++)
    {
        printCharacter(characterDefinitions[i]);
        int sticks = characterCounter[i] * 100 / max * 10 / 10;
        printf("%-5d", sticks);
        printf("%-5d", characterCounter[i]);
        printf("%-5d", max);
        for (int j = 0; j < sticks; j++)
            printf("|");
        printf("\n");
    }
}

void printCharacter(int character)
{
    switch (character)
    {
    case '\t':
        printf("%3s: ", "\\t");
        break;

    case '\n':
        printf("%3s: ", "\\n");
        break;

    case '\r':
        printf("%3s: ", "\\r");
        break;

    case ' ':
        printf("%3s: ", "\' \'");
        break;

    default:
        printf("%3c: ", character);
    }
}

int getMax(int array[], int length)
{
    int max = 0;

    for (int i = 0; i < length; i++)
    {
        if (max < array[i])
            max = array[i];
    }

    return max;
}