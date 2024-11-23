#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

uint32_t get_bit(uint32_t a, uint8_t n)
{
    return (a >> n) & 1;
}
int fb(uint32_t a, uint32_t b, uint8_t k)
{
    uint8_t swaps = 0;
    for (int i = 0; i < 32; i++)
    {
        swaps += (get_bit(a, i) != get_bit(b, i));
    }

    return swaps <= k;
}

int main()
{
    printf("%i\n", fb(0xFF, 0, 3));
    printf("%i\n", fb(0xF - 1, 0, 3));
    printf("%i\n", fb(7, 0, 3));
}
