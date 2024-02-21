#include <stdio.h>
#include "stdbool.h"

int main()
{
    // bool signelLineComment = false;

    bool isSingleLineComment = false;
    bool isMultiLineComment = false;
    bool isComment = false;
    bool doNotPrintChar = false;
    /*
        bool multiLineComment = true;
    */
    char buffer[2] = {"\0\0"};
    char character;

    // /* Multi line comment should be ignored in single line one */
    while ((buffer[1] = getchar()) != EOF)
    {
        if (!isComment)
        {
            isSingleLineComment = buffer[0] == '/' && buffer[1] == '/';
            isMultiLineComment = buffer[0] == '/' && buffer[1] == '*';
            isComment = isSingleLineComment || isMultiLineComment;
        }

        if (!isComment)
            if (!doNotPrintChar)
                putchar(buffer[0]);
            else
                doNotPrintChar = false;

        /* // Single line comment must be ignored in multi line one*/
        if (isComment)
        {
            isSingleLineComment &= buffer[1] != '\n';
            isMultiLineComment &= buffer[0] != '*' || buffer[1] != '/';
            isComment = isSingleLineComment || isMultiLineComment;
            doNotPrintChar = true;
        }

        buffer[0] = buffer[1];
    }
}