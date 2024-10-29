#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int char_to_number(char c)
{
    if (isdigit(c))
    {
        return c - '0';
    }
    if (toupper(c) < 'A' || toupper(c) > 'F')
    {
        printf("Invalid character");
        exit(1);
    }
    return toupper(c) - 'A' + 10;
}

int read_number(int b)
{
    char c;
    int n = 0;
    while ((c = getchar()) != EOF)
    {
        n = n * b + char_to_number(c);
    }
    return n;
}

void collapse_spaces()
{
    char c;
    int n = 0;
    while (isspace((c = getchar())))
    {
    }
    ungetc(c, stdin);
}

void read_paragraph(char delimiter)
{
    char c;
    while ((c = getchar()) != EOF)
    {
        if (isspace(c))
        {
            collapse_spaces();
            putchar(delimiter);
        }
        else
        {
            putchar(c);
        }
    }
}
int peek()
{
    int c = getchar();
    ungetc(c, stdin);
    return c;
}
void ignore_comments()
{
    // naive, doesn't check for nesting unclosed comments
    int c;
    int show = 1;
    while ((c = getchar()) != EOF)
    {

        if (c == '/')
        {

            if ((c = getchar()) == '*')
            {
                show = 0;
                continue;
            }

            else
            {
                if (show)
                {
                    putchar('/');
                }
            }
        }

        if (c == '*')
        {
            if ((c = getchar()) == '/')
            {
                show = 1;
                continue;
            }
        }

        if (show)
            putchar(c);
    }

    putchar('\n');
}

int main()
{

    ignore_comments();
    return 0;
}