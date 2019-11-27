// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "leetcode_util.h"
using namespace std;

class Solution {
    inline bool isBalanced(const pair<int, int> & paren_count) {
        return paren_count.first == paren_count.second;
    }
public:
    vector<string> generateParenthesis(int n) {
        if (n < 0) return {};
        if (n == 0) return {""};
        vector<string> vec_seq = {"("};
        vector<pair<int, int>> vec_paren_count = {{1, 0}};
        for (auto i = 0; i != 2 * n - 1; ++i) {
            const auto len = vec_seq.size();
            for (auto j = 0; j != len; ++j) {
                const auto left_count  = vec_paren_count[j].first,
                           right_count = vec_paren_count[j].second;
                if (isBalanced(vec_paren_count[j])) {
                    if (left_count < n) {
                        vec_seq[j] += '(';
                        ++vec_paren_count[j].first;
                    }
                } else {
                    if (left_count < n) {
                        vec_seq.push_back(vec_seq[j] + '(');
                        vec_paren_count.push_back({left_count + 1, right_count});
                    }
                    if (right_count < n) {
                        vec_seq[j] += ')';
                        ++vec_paren_count[j].second;
                    }
                }
            }
        }
        return vec_seq;
    }
};

int main() {
    Solution sol;
    for (auto i : {-1, 0, 1, 2, 3, 4, 5}) {
        auto parens = sol.generateParenthesis(i);
        cout << i << "\tLength: "  << to_string(parens.size())
                  << "\tContent: " << leetcode::to_string(parens) << endl;
    }
    // The sequence is actually Catalan numbers, see https://oeis.org/A000108.
    for (auto i : {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14})
        cout << sol.generateParenthesis(i).size() << ",";
    cout << endl;
}
