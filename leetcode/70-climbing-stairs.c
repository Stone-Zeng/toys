// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include <stdio.h>

int climbStairs(int n) {
    int fib_0 = 1, fib_1 = 1, fib_2 = 0;
    for (int i = 0; i < n - 1; ++i) {
        fib_2 = fib_0 + fib_1; fib_0 = fib_1; fib_1 = fib_2;
    }
    return fib_1;
}

int main() {
    printf("%d\n", climbStairs(1));
    printf("%d\n", climbStairs(2));
    printf("%d\n", climbStairs(3));
    printf("%d\n", climbStairs(4));
    printf("%d\n", climbStairs(5));
    printf("%d\n", climbStairs(6));
    printf("%d\n", climbStairs(7));
    printf("%d\n", climbStairs(20));
}
