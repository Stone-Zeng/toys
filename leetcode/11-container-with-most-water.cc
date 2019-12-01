// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <vector>
#include "leetcode_util.h"
using namespace std;

class Solution {
public:
    int maxArea(vector<int> & height) {
        auto len = height.size();
        int area = 0;
        for (size_t i = 0; i != len - 1; ++i)
            for (size_t j = i + 1; j != len; ++j) {
                int new_area = (j - i) * min(height[i], height[j]);
                if (new_area > area) area = new_area;
            }
        return area;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> data = {
        {1,2},
        {0,0},
        {1222,1222,1222},
        {1,8,6,2,5,4,8,3,7},
    };
    for (auto & height : data) {
        cout << leetcode::to_string(sol.maxArea(height)) << endl;
    }
}
