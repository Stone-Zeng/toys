// 29. Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/

#include <stdio.h>

#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)

int _divide(int dividend, int divisor) {
    int final = 0, result = 0, temp = 0;
    while (dividend >= divisor) {
        result = 1;
        temp = divisor;
        while (temp <= (dividend >> 1)) {
            result += result;
            temp += temp;
        }
        dividend -= temp;
        final += result;
    }
    return final;
}

int _divide_min_int(int divisor) {
    if (divisor == -1)
        return MAX_INT;  // Overflow actually
    if (divisor == 1)
        return MIN_INT;
    if (divisor == MIN_INT)
        return 1;
    if (divisor > 0) {
        int dividend = -(MIN_INT + divisor);
        return -_divide(dividend, divisor) - 1;
    } else {
        int dividend = -(MIN_INT - divisor);
        return _divide(dividend, -divisor) + 1;
    }
}

int divide(int dividend, int divisor) {
    if (dividend == MIN_INT)
        return _divide_min_int(divisor);

    if (divisor == MIN_INT)
        return 0;

    int is_positive = 1;
    if (dividend > 0) {
        if (divisor < 0) {
            divisor = -divisor;
            is_positive = 0;
        }
    } else {
        dividend = -dividend;
        if (divisor > 0)
            is_positive = 0;
        else
            divisor = -divisor;
    }

    if (dividend < divisor) return 0;
    if (divisor == 1) {
        if (is_positive)
            return dividend;
        else
            return -dividend;
    }

    if (is_positive)
        return _divide(dividend, divisor);
    else
        return -_divide(dividend, divisor);
}

#define TEST(a, b) \
    printf("%d/%d\t= %d; %d\n", (a), (b), (a) / (b), (a) / (b) - divide((a), (b)))

int main() {
    TEST(10, 12);
    TEST(11, 12);
    TEST(12, 12);
    TEST(13, 12);
    TEST(14, 12);
    TEST(22, 12);
    TEST(23, 12);
    TEST(24, 12);
    TEST(25, 12);
    TEST(26, 12);
    TEST(10, -12);
    TEST(11, -12);
    TEST(12, -12);
    TEST(13, -12);
    TEST(14, -12);
    TEST(22, -12);
    TEST(23, -12);
    TEST(24, -12);
    TEST(25, -12);
    TEST(26, -12);
    TEST(123435, 12);
    TEST(123436, 12);
    TEST(123437, 12);

    TEST(MAX_INT, -12);
    TEST(MIN_INT, -1);
    TEST(MIN_INT, -2);
    TEST(MIN_INT, -3);
    TEST(MIN_INT, -4);
    TEST(MIN_INT,  1);
    TEST(MIN_INT,  2);
    TEST(MIN_INT,  3);
    TEST(MIN_INT,  4);
    TEST(MIN_INT+1, -1);
    TEST(MIN_INT+1, -2);
    TEST(MIN_INT+1,  1);
    TEST(MIN_INT+1,  2);


    TEST(MIN_INT, MIN_INT);
    TEST(MIN_INT, MAX_INT);
    TEST(-1010369383, -2147483648);
}
