#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

uint64_t get_last_b_bits(uint64_t a, uint8_t b)
{
    // 0000 0000 0100 1011
    // 0000 0000 0000 0111
    //~ 1111 1111 1111 1000
    // <<3
    uint64_t mask = ~(0xFFFFFFFFFFFFFFFF << b);
    return a & mask;
}

uint64_t fa(uint64_t a, uint8_t b)
{
    uint64_t max = 0;
    for (int i = 0; i < 64; i++)
    {
        uint64_t x = get_last_b_bits(a >> i, b);
        printf("x: %llu\n", x);
        if (x > max)
            max = x;
    }

    return max;
}

int main()
{
    printf("%llu", fa((6 << 4) + 7, 3));
}
