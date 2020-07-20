// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/

#include <iostream>
#include <unordered_map>
#include <vector>
#include "leetcode_util.h"
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= 1) return false;
        unordered_map<int, int> map;
        for (size_t i = 0; i != nums.size(); ++i) {
            auto nums_i = nums[i];
            if (map.find(nums_i) != map.cend() && i - map[nums_i] <= k) return true;
            map[nums_i] = i;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> data = {
        {{1},1},
        {{1,1},0},
        {{1,2},1},
        {{1,2,3,1},3},
        {{1,0,1,1},1},
        {{1,2,3,1,2,3},2},
        {{4,1,2,1,3,5},3},
    };
    for (auto & p: data) {
        cout << leetcode::to_string(sol.containsNearbyDuplicate(p.first, p.second)) << endl;
    }
}
