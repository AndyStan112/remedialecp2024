#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int is_special_charcter(char c)
{
    char *special_characters = "!?.,:; \t\n";
    if (strchr(special_characters, c) != NULL)
        return 1;
    return 0;
}

char *clean_special_charcters(char *str)
{
    while (is_special_charcter(*str) && (*str != '\0'))
    {
        str++;
    }
    return str;
}

void print_words(char *s)
{
    while ((*s) != '\0')
    {
        s = clean_special_charcters(s);

        while (!is_special_charcter(*s) && ((*s) != '\0'))
        {
            putchar(*s);
            s++;
        }
        putchar('\n');
    }
}

int sscanprint(char *str, char *format)
{
    int k = 0;
    while (*str != '\0' && *format != '\0')
    {
        while (*format != '%')
        {

            if (*str != *format)
            {
                printf("Got difference in strings\n%s\n%s\n", str, format);
                return k;
            }
            str++, format++;
            if (*format == '\0' || *str == '\0')
                return k;
        }
        format++;

        if (*format == 'd')
        {
            char *endptr;
            endptr = str;
            int n = strtol(str, &endptr, 10);
            printf("%i\n", n);
            if (endptr == str)
                return k;
            str = endptr;
            k++;
            format++;
        }
        else if (*format == 'f')
        {
            char *endptr;
            endptr = str;
            double n = strtod(str, &endptr);
            printf("%lf\n", n);
            if (endptr == str)
                return k;
            str = endptr;
            k++;
            format++;
        }
        else if (isdigit(*format))
        {
            char *endptr;
            int n = strtol(format, &endptr, 10);
            format = endptr;
            if (*format == 's')
            {
                while (n != 0 && *str != '0')
                {
                    putchar(*str++);
                    n--;
                }
                k++;
                putchar('\n');
            }
            else
            {
                if (*str == '%')
                {
                    str++;
                    char *endptr;
                    endptr = str;
                    int m = strtol(str, &endptr, 10);
                    if (m != n)
                        return k;
                    str = endptr;
                }
            }
        }
        else
        {
            format++;
        }
    }

    return k;
}

char *clean_spaces(char *str)
{
    while (isspace(*str))
    {
        str++;
    }
    return str;
}

void split_strings(char *str, char **addrs, int n)
{
    str = clean_spaces(str);
    int k = 0;
    for (; k < n - 1 && *str != '\0'; k++)
    {
        addrs[k] = str;
        while (*str != '\0' && !isspace(*str))
            str++;
        str = clean_spaces(str);
    }
    addrs[k] = NULL;
}
// return all of the whitespace separated numbers from str
int *read_numbers(char *str, int *l)
{
    int k = 0;
    int *arr = malloc(0);
    str = clean_spaces(str);
    while (*str != '\0')
    {
        char *endptr;
        double n = strtod(str, &endptr);
        str = endptr;
        k++;
        int *tmp = realloc(arr, k * sizeof(int));
        if (!tmp)
            exit(1);
        arr = tmp;
        arr[k - 1] = n;
        str = clean_spaces(str);
    }
    *l = k;
    return arr;
}

int main()
{
    // Prob 3
    //  char *str = "Buna, eu sunt Andy!!";
    //  print_words(str);

    // Prob 4
    //  int k = sscanprint("AC 123 12.567 %3hh 34 abcdf", "AC %d %f %3hh %d %5s");
    //  printf("%i\n", k);

    // Prob 6
    // char *str = "    Ana are mere andrei are pere";
    // char **addrs = malloc(20 * (sizeof(char *)));
    // split_strings(str, addrs, 20);
    // char *addrs[20];
    // with char* addrs[20]:
    //  for (int i = 0; i < 20; i++)
    //  {
    //      if (addrs[i] == NULL)
    //          return 0;
    //      printf("%s\n", addrs[i]);
    //  }
    // WITH char**adrs
    //  while (*addrs != NULL)
    //  {
    //      printf("%s\n", *addrs);
    //      addrs++;
    //  }
    // Dynamic allocation example
    char *str = "1234 123 443";
    int *arr;
    int k;
    arr = read_numbers(str, &k);
    for (int i = 0; i < k; i++)
    {
        printf("%i\n", arr[i]);
    }

    return 0;
}