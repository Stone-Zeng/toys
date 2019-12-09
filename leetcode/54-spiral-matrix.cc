// 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <vector>
#include "leetcode_util.h"
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> & matrix) {
        if (matrix.empty())
            return {};
        int i = 0, j = 0,
            i_min = 0, j_min = 0,
            i_max = matrix.size() - 1, j_max = matrix[0].size() - 1;
        vector<int> result;
        while (true) {
            for (j = j_min; j <= j_max; ++j)
                result.push_back(matrix[i_min][j]);
            if (++i_min > i_max)
                return result;
            for (i = i_min; i <= i_max; ++i)
                result.push_back(matrix[i][j_max]);
            if (--j_max < j_min)
                return result;
            for (j = j_max; j >= j_min; --j)
                result.push_back(matrix[i_max][j]);
            if (--i_max < i_min)
                return result;
            for (i = i_max; i >= i_min; --i)
                result.push_back(matrix[i][j_min]);
            if (++j_min > j_max)
                return result;
        }
    }
};

int main() {
    Solution sol;
    vector<vector<vector<int>>> data = {
        {},
        {{}},
        {{1}},
        {{1,2,3,4,5}},
        {{1,2,3},{4,5,6}},
        {{1},{10},{100},{1000}},
        {{1,2},{10,20},{100,200},{1000,2000}},
        {{1,2,3},{4,5,6},{7,8,9}},
        {{1,2,3,4},{5,6,7,8},{9,10,11,12}},
        {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}},
    };
    for (auto i: data)
        cout << leetcode::to_string(sol.spiralOrder(i)) << endl;
}
