// 6. ZigZag Conversion
// https://leetcode.com/problems/zigzag-conversion/

#include <iostream>
#include <string>
#include "leetcode_util.h"
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        int len = s.size();
        if (len <= 2) return s;
        string result;

        int i = 0, j = 0, k = 0, l = 0;

        k = 2 * j * (numRows - 1);
        while (k < len) {
            result += s[k];
            ++j;
            k = 2 * j * (numRows - 1);
        }
        ++i;

        while (i < numRows - 1) {
            j = 0;
            k = 2 * j * (numRows - 1) + i;
            l = 2 * (j + 1) * (numRows - 1) - i;
            while (true) {
                if (k < len) {
                    result += s[k];
                    if (l < len) result += s[l];
                } else {
                    if (l < len) result += s[l];
                    else break;
                }
                ++j;
                k = 2 * j * (numRows - 1) + i;
                l = 2 * (j + 1) * (numRows - 1) - i;
            }
            ++i;
        }

        j = 0;
        k = (2 * j + 1) * (numRows - 1);
        while (k < len) {
            result += s[k];
            ++j;
            k = (2 * j + 1) * (numRows - 1);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<pair<string, int>> data = {
        {"1234567890ABCDEF", 3},
        {"1234567890ABCDEF", 4},
        {"1234567890ABCDEF", 5},
        {"1234567890ABCDE", 1},
        {"1234567890ABCDE", 2},
        {"1234567890ABCDE", 3},
        {"1234567890ABCDE", 4},
        {"1234567890ABCDE", 5},
    };
    for (const auto & i : data) {
        cout << sol.convert(i.first, i.second) << endl;
    }
}
