// 66. Plus One
// https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            if (*iter != 9) {
                (*iter)++;
                return digits;
            }
            *iter = 0;
            if (iter + 1 == digits.rend()) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        return digits;
    }
};

int main() {
    vector<vector<int>> data = {
        {1,2,3},
        {1,2,3,4},
        {1,2,3,9},
        {9},
        {9,9,9,9},
        {0},
    };
    for (auto v: data) {
        Solution sol;
        for (auto i: sol.plusOne(v)) cout << i << ", ";
        cout << endl;
    }
}
