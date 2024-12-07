#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
int extractOdds(int v[], int n, int *arr[], int capacity)
{
    int moved_counter = 0;
    size_t i = 0;
    for (; i < n && moved_counter < capacity; i++)
    {
        if (v[i] % 2 == 1)
        {

            arr[moved_counter] = v + i;
            moved_counter++;
        }
    }

    if (i < n)
        return -1;
    return moved_counter;
}

int countAllignedAddresses(int *addr[])
{
    int k = 0;
    int *p;
    while ((p = *addr) != NULL)
    {
        if (((int)p & 0xf) == 0)
        {
            k++;
        }
        addr++;
    }
    return k;
}
char *cleanSpaces(char *str)
{
    while (isspace(*str))
    {
        str++;
    }
    return str;
}

int char_to_number(char c)
{
    if (isdigit(c))
    {
        return c - '0';
    }
    if (toupper(c) < 'A' || toupper(c) > 'F')
    {
        printf("Invalid character");
    }
    return toupper(c) - 'A' + 10;
}

double parse_string(char *str, char **endptr, int base)
{
    str = cleanSpaces(str);
    double d = 0;
    int sign = 1;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }
    else if (*str == '\0')
    {
        return 0;
    }

    while (isdigit(*str) || ((base > 10) && (toupper(*str) >= 'A' && toupper(*str) <= 'F')))
    {
        d = d * base + char_to_number(*str);
        str++;
    }

    if (*str == '.')
    {

        str++;
        double div = 1;
        while (isdigit(*str) || ((base > 10) && (toupper(*str) >= 'A' && toupper(*str) <= 'F')))
        {

            div *= base;
            d = d + char_to_number(*str) / div;
            str++;
        }
    }
    if (endptr != NULL)
        *endptr = str;
    return sign * d;
};

double _strtod(char *str, char **endptr)
{
    return parse_string(str, endptr, 10);
}

double strtoh(char *str, char **endptr)
{
    return parse_string(str, endptr, 16);
}

char *parse_number_in_string(char *str)
{
    str = cleanSpaces(str);
    char *endptr;
    int n = strtol(str, &endptr, 10);
    if (*endptr == '.')
    {
        printf("float:%g\n", strtod(str, &endptr));
    }
    else
    {
        printf("int:%i\n", n);
    }
    return endptr;
}
void parse_numbers_in_string(char *str)
{
    str = cleanSpaces(str);
    char *endptr;
    while (*(str = parse_number_in_string(str)))
    {
        str = cleanSpaces(str);
    }
}

int main()
{
    // extract odds
    int a[] = {1, 2, 3, 4, 5};
    int *b[20];
    int n = extractOdds(a, 5, b, 20);

    for (size_t i = 0; i < n; i++)
    {
        printf("%i\n", b[i]);
    }

    // alligned addresses
    int *c[20] = {1, 16, 22, NULL};
    printf("Alligned addresses:  %i\n", countAllignedAddresses(c));
    // double handling

    char szOrbits[] = "365.24 29.53";
    char szOrbitsh[] = "16D.3D70A3D70A3D70A3D70A 1D.87AE147AE147AE147AE1";
    char *pEnd;
    double d1, d2, dh1, dh2;
    d1 = strtoh(szOrbits, &pEnd);
    d2 = strtoh(pEnd, NULL);
    dh1 = strtoh(szOrbitsh, &pEnd);
    dh2 = strtoh(pEnd, NULL);
    printf("The moon completes %.2f == %.2f orbits per Earth year.\n", d1 / d2, dh1 / dh2);

    // number parsing
    char *numbers = "123 65.433 8653 12.35";
    parse_numbers_in_string(numbers);
    return 0;
}