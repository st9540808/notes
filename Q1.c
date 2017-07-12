#include <stdio.h>
#include <stdint.h>

uint32_t bit_reverse_u32(uint32_t x)
{
    uint32_t mask = ~0, n = x;
    for (int i = 4; i >= 0; i--) {
        mask ^= mask << (1 << i);
        n = ((n & ~mask) >> (1 << i)) | ((n & mask) << (1 << i));
    }
    return n;
}


uint32_t bit_reverse_recursive(uint32_t x, int length)
{
    static int pos = 0;
    if (length == 2)
        return ((x & (1 << pos++)) << 1) | ((x & (1 << pos++)) >> 1);
    else
        return (bit_reverse_recursive(x, length / 2) << length / 2)
            |  (bit_reverse_recursive(x, length / 2) >> length / 2);
}

uint32_t func(uint32_t x)
{
    uint32_t n = x;
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >>  8) | ((n & 0x00ff00ff) <<  8);
    n = ((n & 0xf0f0f0f0) >>  4) | ((n & 0x0f0f0f0f) <<  4);
    n = ((n & 0xcccccccc) >>  2) | ((n & 0x33333333) <<  2);
    n = ((n & 0xaaaaaaaa) >>  1) | ((n & 0x55555555) <<  1);
    return n;
}

void print_bit(uint32_t x)
{
    for (int i = 0; i < 32; i++) {
        uint32_t temp = x & (1 << (31 - i));
        printf("%d", temp != 0 ? 1 : 0);
    }
    printf("\n");
}


int main()
{
    int x = 1207959552;
    print_bit(bit_reverse_u32(x));
    print_bit(x);
}
