// 1. Two Sum
// https://leetcode.com/problems/two-sum/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (auto i = nums.begin(); i != nums.end() - 1; ++i) {
            auto j = find(i + 1, nums.end(), target - *i);
            if (j != nums.end())
                return {static_cast<int>(i - nums.begin()),
                        static_cast<int>(j - nums.begin())};
        }
        return {};
    }
};

template<typename T>
void _print(const vector<T> & v) {
    for (const auto & i: v)
        cout << i << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> v1{2, 7, 11, 15};
    vector<int> v2{3, 2, 4, 1, 0, 5};
    vector<int> v3{3, 2};
    _print(sol.twoSum(v1, 9));
    _print(sol.twoSum(v2, 8));
    _print(sol.twoSum(v3, 5));
}
