// 190. Reverse Bits
// https://leetcode.com/problems/reverse-bits/

#include <stdint.h>
#include <stdio.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t r = 0;
    uint32_t i = 2147483648; // 2^31
    while (i >= 1) {
        r += (n % 2) * i;
        n /= 2;
        i /= 2;
    }
    return r;
}

int main() {
    printf("%u\n", reverseBits(0b00000000000000000000000000001011));
    printf("%u\n", reverseBits(0b00000010100101000001111010011100));
}
