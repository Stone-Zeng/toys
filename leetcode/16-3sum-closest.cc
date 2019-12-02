// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
#include "leetcode_util.h"
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> & nums, int target) {
        if (nums.size() <= 3)
            return accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int sum = 0, new_sum = 0,
            delta = INT_MAX, new_delta = INT_MAX;
        auto i = nums.begin(), j = i, k = i, nums_end = nums.end();
        for (; i != nums_end; ++i)
            for (j = i + 1; j != nums_end; ++j)
                for (k = j + 1; k != nums_end; ++k) {
                    if (delta == 0) return target;
                    new_sum = *i + *j + *k;
                    new_delta = abs(new_sum - target);
                    if (new_delta < delta) {
                        sum = new_sum;
                        delta = new_delta;
                        continue;
                    }
                    if (new_sum - target > 0) break;
                }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> data = {
        {{1,2,3},4},
        {{1,2,5},4},
        {{1,2,5,2},4},
        {{0},1},
        {{29,16,92,56,25,62,59,31,-52,-57,100,-68,-33,-93,-77,31,7,-44,-52,-30,-72,71,16,-68,-1,67,-58,21,-7,-90,-67,59,-38,-19,13,70,37,16,-86,25,-20,87,61,80,16,33,-50,48,-44,9}, 23},
        {{0,7,-4,-7,0,14,-6,-4,-12,11,4,9,7,4,-10,8,10,5,4,14,6,0,-9,5,6,6,-11,1,-8,-1,2,-1,13,5,-1,-2,4,9,9,-1,-3,-1,-7,11,10,-2,-4,5,10,-15,-4,-6,-8,2,14,13,-7,11,-9,-8,-13,0,-1,-15,-10,13,-2,1,-1,-15,7,3,-9,7,-1,-14,-10,2,6,8,-6,-12,-13,1,-3,8,-9,-2,4,-2,-3,6,5,11,6,11,10,12,-11,-14}, 133},
    };
    for (auto i: data) {
        cout << leetcode::to_string(sol.threeSumClosest(i.first, i.second)) << endl;
    }
}
