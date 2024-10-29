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
        printf("Invalid character\n");
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
        ;
    }
    return n;
}

int main()
{

    printf("%d\n", read_number(16));
    return 0;
}