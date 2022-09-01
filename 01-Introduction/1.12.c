#include <stdio.h>

// Or include stdbool.h instead of
#define true 1
#define false 0
#define bool int

int main()
{
    bool isAwaitingNewWord = false;
    int ch;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n' || ch == ' ' || ch == '\t')
            isAwaitingNewWord = true;
        else
        {
            if(isAwaitingNewWord)
            {
                isAwaitingNewWord = false;
                putchar('\n');
            }
            putchar(ch);
        }
    }
}