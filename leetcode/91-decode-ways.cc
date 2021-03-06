// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/

// #include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "leetcode_util.h"
using namespace std;

const vector<int> kFibonacciVector =
    {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};

class Solution {
    inline int numDecodingsHelper(const string & s, int left, int right) {
        auto len = right - left + 1;
        if (len == 1) return s[left] == '0' ? 0 : 1;
        if (s[right] == '0') return fibonacci(len - 2);
        if (s[right] > '6' && s[right - 1] == '2') return fibonacci(len - 1);
        return fibonacci(len);
    }
    int fibonacci(int n) {
        if (n < kFibonacciVector.size()) return kFibonacciVector[n];
        return fibonacci(n - 2) + fibonacci(n - 1);
    }
public:
    int numDecodings(string s) {
        if (s.length() == 1) return s == "0" ? 0 : 1;
        auto i = 0;
        auto result = 1;
        while (i < s.length()) {
            auto j = i;
            while (s[j] > '0' && s[j] <= '2' && j < s.length() - 1) ++j;
            auto num = numDecodingsHelper(s, i, j);
            if (num == 0) return 0;
            result *= num;
            i = j + 1;
        }
        return result;
    }
};

int main() {
    Solution sol;
    for (const auto & s: {
        "12",
        "18",
        "28",
        "226",
        "217",
        "227",
        "2200",
        "0",
        "1",
        "1284122012832174321312121232221",
        "222222222222222222222222222222222222",
        "52152023223211223148151714101115131216172412105"
    }) {
        auto n = sol.numDecodings(s);
        cout << "\"" << s << "\" => " << n << endl;
    }
}
