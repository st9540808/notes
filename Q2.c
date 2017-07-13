#include <stdio.h>
#include <stdint.h>
#include "print_bit.h"

uint32_t half_add(uint32_t a, uint32_t b);
uint32_t multiply(uint32_t a, uint32_t b)
{
    if (b == 0) return 0;
    uint32_t partial_sum = a & ~((b & 1) - 1);
    return half_add(partial_sum, multiply(a , b >> 1) << 1);
}


uint32_t half_add_iterative(uint32_t a, uint32_t b)
{
    while (b != 0) {
        uint32_t sum = a ^ b;
        uint32_t carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}

uint32_t half_add(uint32_t a, uint32_t b)
{
    if (b == 0) return a;
    uint32_t sum = a ^ b;
    uint32_t carry = (a & b) << 1;
    return half_add(sum, carry);
}

uint32_t mask(uint32_t x)
{
    uint32_t lsb = x & 1;
    return ~(lsb - 1);
}


int main()
{
    printf("%d\n", multiply(2, 3));
    return 0;
}
