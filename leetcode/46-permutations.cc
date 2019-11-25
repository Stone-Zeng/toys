// 46. Permutations
// https://leetcode.com/problems/permutations/

#include <algorithm>
#include <iostream>
#include <vector>
#include "leetcode_util.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        auto nums_size = nums.size();
        if (nums_size == 0) return {{}};
        if (nums_size == 1) return {nums};
        if (nums_size == 2) return {nums, {nums[1], nums[0]}};
        vector<vector<int>> result;
        vector<int> x;
        for (auto i = 0; i != nums_size; ++i) {
            x = nums;
            x.erase(x.begin() + i);
            for (auto & v: permute(x)) {
                v.push_back(nums[i]);
                result.push_back(v);
            }
        }
        return result;
    }

    // From STL, 10x faster.
    // vector<vector<int>> permute(vector<int>& nums) {
    //     decltype(permute(nums)) result;
    //     do
    //         result.push_back(nums);
    //     while (next_permutation(nums.begin(), nums.end()));
    //     return result;
    // }
};

int main() {
    vector<vector<int>> prices {
        {},
        {0},
        {12,15},
        {1,2,3},
        {1,2,3,4},
        {1,2,3,4,5},
        {1,2,3,4,5,6},
        {1,2,3,4,5,6,7},
        {1,2,3,4,5,6,7,8},
        {1,2,3,4,5,6,7,8,9},
        // {1,2,3,4,5,6,7,8,9,10},
        // {1,2,3,4,5,6,7,8,9,10,11},
    };
    Solution sol;
    for (auto i: prices) {
        if (i.size() < 5)
            cout << leetcode::to_string(sol.permute(i)) << endl;
        cout << "Length: " << sol.permute(i).size() << endl;
    }
}
