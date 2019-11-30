// 50. Pow(x, n)
// https://leetcode.com/problems/powx-n/

#include <math.h>
#include <stdio.h>

#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)

double _myPow(double x, int n) {
    double r = 1.0;
    while (n >= 1) {
        double _r = x;
        int _n = 1;
        while (_n < n / 2) {
            _r *= _r;
            _n *= 2;
        }
        r *= _r;
        n -= _n;
    }
    return r;
}

double myPow(double x, int n) {
    if (n == 0) return 1.0;
    if (x == 0.0) {
        if (n > 0) return 0.0;
        if (n < 0) return INFINITY;
    }
    if (x == 1.0) return 1.0;
    if (n == 1) return x;
    if (n == MIN_INT) {
        double _r = 1.0 / _myPow(x, -(n / 2));
        return _r * _r;
    }
    if (n < 0)
        return 1.0 / _myPow(x, -n);
    return _myPow(x, n);
}

void _test(double x, int n) {
    double pow_v    = pow(x, n),
           my_pow_v = myPow(x, n);
    printf("%e ^ %d:\t%s\n\t%f\n\t%f\n",
           x, n, pow_v == my_pow_v ? "true" : "false", pow_v, my_pow_v);
}

int main() {
    _test(2.0, 5);
    _test(2.0, 6);
    _test(2.0, 7);
    _test(2.0, 8);
    _test(2.0, 9);
    _test(2.0, 10);
    _test(2.1, 3);
    _test(2.0, -2);

    int ns[] = {0, 1, -1, MAX_INT, MAX_INT - 1, MIN_INT, MIN_INT + 1};
    double xs[] = {
        0.0, 1.0,  2.0,  40.0,  3.14e-12,  100.0,
            -1.0, -2.0, -40.0, -3.14e-12, -100.0,
        1+2e-7, 1+3e-8, -1+2e-7, -1+3e-8};
    const size_t ns_size = 7;
    const size_t xs_size = 15;

    for (size_t i = 0; i != ns_size; ++i) {
        printf("\n============================================================\n\n");
        for(size_t j = 0; j != xs_size; ++j)
            _test(xs[j], ns[i]);
    }
}
