// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> & nums, int k) {
        sort(nums.begin(), nums.end());
        return *(nums.end() - k);
    }
};

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> data = {
        {{3,2,1,5,6,4},2},
        {{3,2,3,1,2,4,5,5,6},4},
    };
    for (auto & p: data) {
        cout << sol.findKthLargest(p.first, p.second) << endl;
    }
}
