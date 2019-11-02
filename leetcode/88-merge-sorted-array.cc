// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3{nums1};
        std::merge(nums1.begin(), nums1.begin() + m,
                   nums2.begin(), nums2.begin() + n,
                   nums3.begin());
        nums1 = nums3;
    }
};

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    for (auto i: nums1)
        cout << i << ", ";
    cout << endl;
}
