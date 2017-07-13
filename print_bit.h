#ifndef print_bit
#define print_bit

#include <stdio.h>
#include <stdint.h>

void print_bit_u32(uint32_t x)
{
    for (int i = 0; i < 32; i++)
        printf("%d", (x & (1 << 31 - i)) != 0 ? 1 : 0);
    printf("\n");
}

void print_bit_u16(uint16_t x)
{
    for (int i = 0; i < 16; i++)
        printf("%d", (x & (1 << 15 - i)) != 0 ? 1 : 0);
    printf("\n");
}

#endif
