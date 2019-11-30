// 48. Rotate Image
// https://leetcode.com/problems/rotate-image/

#include <iostream>
#include <vector>
#include "leetcode_util.h"
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        const size_t n = matrix.size();
        for (size_t level = 0; level != n / 2; ++level)
            for (size_t i = 0; i != n - 1 - 2 * level; ++i) {
                auto k = n - 1 - level;
                auto temp = matrix[level][level + i];
                matrix[level][level + i] = matrix[k - i][level];
                matrix[k - i][level] = matrix[k][k - i];
                matrix[k][k - i] = matrix[level + i][k];
                matrix[level + i][k] = temp;
            }
    }
};

int main() {
    Solution sol;
    vector<vector<vector<int>>> data = {
        {},
        {{1}},
        {{1,2},{3,4}},
        {{1,2,3},{4,5,6},{7,8,9}},
        {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}},
    };
    for (auto & m : data) {
        cout << leetcode::to_string(m) << endl;
        sol.rotate(m);
        cout << leetcode::to_string(m) << endl;
    }
}
