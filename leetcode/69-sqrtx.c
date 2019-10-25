// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/

#include <limits.h>
#include <math.h>
#include <stdio.h>

int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    int y = x;
    while (1)
    {
        int z = x / y / 2 + y / 2;
        if (y == z || y - z == 1 || y - z == -1) {
            if (y <= x / y && y + 1 > x / (y + 1))            return y;
            if (y - 1 <= x / (y - 1) && y > x / y)            return y - 1;
            if (y - 2 <= x / (y - 2) && y - 1 > x / (y - 1))  return y - 2;
            return y + 1;
        }
        y = z;
    }
}

#define TEST(x) printf("%d => %d, %f\n", x, mySqrt((x)), sqrt((x)))

int main() {
    for (int i = 0; i < 10000; ++i) TEST(i);
    TEST(INT_MAX);
}
