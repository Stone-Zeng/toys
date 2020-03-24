// 190. Reverse Bits
// https://leetcode.com/problems/reverse-bits/

#include <stdint.h>
#include <stdio.h>

int hammingWeight(uint32_t n) {
    int result = 0;
    while (n >= 1) {
        result += n % 2;
        n >>= 1;
    }
    return result;
}

int main() {
    printf("%d\n", hammingWeight(0b00000000000000000000000000001011));
    printf("%d\n", hammingWeight(0b11111111111111111111111111111101));
    printf("%d\n", hammingWeight(0b00000010100101000001111010011100));
}
