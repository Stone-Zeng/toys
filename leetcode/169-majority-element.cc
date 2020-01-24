// 169. Majority Element
// https://leetcode.com/problems/majority-element/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const auto nums_size = nums.size();
        unordered_map<int, size_t> m;
        for (const auto & i : nums)
            ++m[i];
        for (const auto & j : m)
            if (j.second > nums_size / 2) return j.first;
        return 0;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> data = {
        {3,2,3},
        {2,2,1,1,1,2,2},
    };
    for (auto & i : data)
        cout << sol.majorityElement(i) << endl;
}
