#include <stdio.h>
#include "stdbool.h"
#define n 10

void printBuffer(char buffer[], int length);
bool _isDelimeter(char character);

int main()
{
    char buffer[n];
    char character;

    int lastDelimeterIndex = -1;
    int bufferStart = 0;
    int currentIndex = -1;
    bool isNewLine = true;

    while ((character = getchar()) != EOF)
    {
        if (currentIndex + 1 == n)
            currentIndex = 0;
        else
            currentIndex++;

        bool isDelimeter = _isDelimeter(character);

        if (isNewLine && isDelimeter)
        {
            currentIndex--;
            continue;
        }

        // We don't count multiple delimeters as valid characters
        // also trims in payloads as 'hel   lo'
        if (isDelimeter && _isDelimeter(buffer[currentIndex - 1]))
        {
            currentIndex--;
            continue;
        }

        buffer[currentIndex] = character;

        if (isDelimeter)
            lastDelimeterIndex = currentIndex;

        if (currentIndex == n - 1)
            if (lastDelimeterIndex != -1)
            {
                printBuffer(buffer, lastDelimeterIndex);
                putchar('\n');
                isNewLine = true;

                // Trim delimeters on the end of buffer
                while (currentIndex >= 0 && _isDelimeter(buffer[currentIndex]))
                    currentIndex--;
                
                // Shift buffer to the start
                for (int i = lastDelimeterIndex + 1; i <= currentIndex; i++)
                    buffer[i - lastDelimeterIndex - 1] = buffer[i];

                currentIndex = currentIndex - lastDelimeterIndex - 1;
                lastDelimeterIndex = -1;

                // Reset current index if there was too many delimeters on the end 
                if (currentIndex < 0)
                {
                    currentIndex = -1;
                    isNewLine = true;
                    continue;
                }
            }
            else
            {
                // Dump buffer if word overflow the limit
                printBuffer(buffer, n);
                currentIndex = -1;
            }

        isNewLine = false;
    }

    printBuffer(buffer, currentIndex);
}

void printBuffer(char buffer[], int length)
{
    for (int i = 0; i < length; i++)
        putchar(buffer[i]);
}

bool _isDelimeter(char character)
{
    bool result = character == ' ' || character == '\t';
    return result;
}

//   Hello my fellow friend! How are you? Are fine?          No? Why this line is so big for you?
//   Hello   my fellow friend! How        are     you?     Are   fine?          No? Why this line is so big for you?
// 12345 7890123456789 123456