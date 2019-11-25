// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "leetcode_util.h"
using namespace std;

class Solution {
    const unordered_map<char, vector<char>> digit_alpha_map{
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };

    template <class T_a, class T_b>
    inline vector<string> tuples(const vector<T_a> & a, const vector<T_b> & b) {
        vector<string> result;
        for (const auto & i: a)
            for (const auto & j: b)
                result.push_back(i + j);
        return result;
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> result{""};
        for (const auto & i: digits)
            result = tuples(result, digit_alpha_map.at(i));
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> v{"", "2", "23", "234", "23542", "3457654"};
    for (const auto & s: v)
        cout << leetcode::to_string(sol.letterCombinations(s)) << endl;
}
