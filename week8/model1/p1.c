#include <stdio.h>
#include <ctype.h>

int peek()
{
    int c = getchar();
    ungetc(c, stdin);
    return c;
}

void consume_whitespace()
{
    while (isspace(peek()))
        getchar();
}

int validate_name()
{
    consume_whitespace();

    int c = peek();
    if (!isalnum(c))
        return 0;

    while (isalnum(c = getchar()))
        ;

    if (c != EOF)
        ungetc(c, stdin);

    return 1;
}
// Trebuie sa fie declarat inainte sa fie definit ca avem dependinta reciproca
int validate_term();

int validate_term_list()
{
    consume_whitespace();

    if (!validate_term())
        return 0;

    consume_whitespace();

    while (peek() == ',')
    {
        getchar();
        consume_whitespace();

        if (!validate_term())
            return 0;

        consume_whitespace();
    }

    return 1;
}

int validate_term()
{
    consume_whitespace();

    if (!validate_name())
        return 0;

    consume_whitespace();

    if (peek() == '(')
    {

        getchar();

        if (!validate_term_list())
            return 0;

        consume_whitespace();

        if (getchar() != ')')
            return 0;
    }

    return 1;
}

int validate_term_wrapper()
{
    if (validate_term())
    {
        consume_whitespace();

        if (peek() == EOF)
        {
            printf("Valid term\n");
            return 1;
        }
        else
        {
            printf("Found a valid term but got unexpected input after term termination\n");
            return 0;
        }
    }
    else
    {
        printf("Invalid term\n");
        return 0;
    }
}

int main()
{
    validate_term_wrapper();
    return 0;
}