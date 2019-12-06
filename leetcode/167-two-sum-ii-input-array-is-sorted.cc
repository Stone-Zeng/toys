// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <algorithm>
#include <iostream>
#include <vector>
#include "leetcode_util.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> & numbers, int target) {
        if (numbers.size() == 2) {
            if (numbers[0] + numbers[1] == target)
                return {1, 2};
            else
                return {};
        }
        const auto begin = numbers.begin(), end = numbers.end();
        for (auto i = begin; i != end - 1; ++i) {
            auto j = lower_bound(i + 1, end, target - *i);
            if (j != end && *i + *j == target)
                return {static_cast<int>(i - begin + 1), static_cast<int>(j - begin + 1)};
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> data = {
        {{2,7,11,15}, 9},
        {{0,0,3,4}, 0},
        {{1,2,3,4}, 7},
        {{-999,-948,-914,-874,-823,-805,-801,-779,-739,-552,-539,-517,-514,-502,-477,-417,-348,-339,-317,-287,-275,-242,-139,-60,-37,-35,-7,6,38,64,87,99,160,267,270,341,493,510,536,587,674,707,720,724,754,793,806,856,925,928}, 102},
    };
    for (auto p : data) {
        const auto v = sol.twoSum(p.first, p.second);
        cout << leetcode::to_string(v) << "; " << p.first[v[0] - 1] << ", " << p.first[v[1] - 1] << endl;
    }
}
