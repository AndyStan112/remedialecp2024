#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

int isSorted(unsigned t[], unsigned n)
{
    if (n < 3)
        return 1;
    int rising = t[0] < t[1];
    for (int i = 1; i < n - 1; i++)
    {
        if ((rising && (t[i] > t[i + 1])) || (!rising && (t[i] < t[i + 1])))
            return 0;
    }
    return 1;
}

int arr(int x[], unsigned nx, int y[], unsigned ny)
{
    int i = 0, j = 0;
    while (i < nx && j < ny)
    {
        if (x[i] == y[j])
        {
            j++;
        }
        i++;
    }
    return (j == ny);
}

int add(unsigned a[], size_t na, unsigned b[], size_t nb, unsigned c[], size_t nc)
{
    int nmin, nmax;
    unsigned *xmax;
    if (na < nb)
    {
        nmin = na;
        nmax = nb;
        xmax = b;
    }
    else
    {
        nmin = nb;
        nmax = na;
        xmax = a;
    }

    if (nmax > nc)
    {
        return -1;
    }
    int co = 0;

    for (int i = 0; i < nmin; i++)
    {
        int s = a[i] + b[i] + co;
        co = s > 9;
        s = s % 10;
        c[i] = s;
    }
    do
    {
        c[nmin] = xmax[nmin] + co;
        nmin++;

    } while (nmin < nmax);
    return nmin;
}

uint32_t set_bit(uint32_t set, size_t k)
{

    // 0100
    // 0001 << 2
    if (k < 0 || k > 27)
        return set;
    return set | (1 << k);
}

uint32_t get_letter_set(char s[])
{
    int i = 0;
    uint32_t set = 0;
    while (s[i] != '\0')
    {

        set = set_bit(set, tolower(s[i]) - 'a');
        i++;
    }
    return set;
}

void print_set(uint32_t set)
{
    for (int i = 0; i < 28; i++)
    {
        if ((set >> i) & 1)
        {
            putchar(i + 'a');
        }
    }
}
int main()
{
    // int x[] = {1, 2, 3};
    // int y[] = {1, 2, 4, 3};

    // if (arr(y, 4, x, 3))
    // {
    //     printf("can");
    // }
    // else
    // {
    //     printf("cannot");
    // }

    // int x[] = {1, 2, 3};
    // int y[] = {1, 2, 9, 4};
    // int c[5];
    // int n = add(x, 3, y, 4, c, 5);
    // printf("Number of elements : %u\n", n);
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     printf("%u", c[i]);
    // }

    // 0->A
    // 1-> B
    // 2 -> C

    uint32_t set = 0;
    // 0111 1111
    set = get_letter_set("Akmzefg;']klp");

    printf("%x\n", set);
    print_set(set);
    return 0;
}