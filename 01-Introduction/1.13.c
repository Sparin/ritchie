#include <stdio.h>

// Or include stdbool.h instead of
#define true 1
#define false 0
#define bool int

#define MAX_WORD_LENGTH 25

int main()
{
    bool isAwaitingNewWord = false;
    int counter = 0;
    int wordLengthCounter[MAX_WORD_LENGTH];
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
        wordLengthCounter[i] = 0;
    int character;
    while ((character = getchar()) != EOF)
    {
        if (character == '\n' || character == ' ' || character == '\t')
        {
            if (isAwaitingNewWord == false)
            {
                if(counter < MAX_WORD_LENGTH)
                    wordLengthCounter[counter - 1]++;
                counter = 0;
            }
            isAwaitingNewWord = true;
        }
        else
        {
            isAwaitingNewWord = false;
            counter++;
        }
    }

    int max = getMax(wordLengthCounter, MAX_WORD_LENGTH);

    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        printf("%3d: ", i + 1);
        int sticks = wordLengthCounter[i] * 100 / max * 10 / 10;
        printf("%-5d", sticks);
        printf("%-5d", wordLengthCounter[i]);
        printf("%-5d", max);
        for (int j = 0; j < sticks; j++)
            printf("|");
        printf("\n");
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