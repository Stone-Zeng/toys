// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>
#include "leetcode_util.h"
using namespace std;

class Solution {
    int find_left(const vector<int> & nums, int left, int right, int target) {
        if (nums[left] == target)
            return left;
        if (left + 1 == right) {
            if (nums[right] == target)
                return right;
            else
                return -1;
        }
        int half = (left + right) / 2;
        if (nums[half] < target)
            left = half;
        else
            right = half;
        return find_left(nums, left, right, target);
    }

    int find_right(const vector<int> & nums, int left, int right, int target) {
        if (nums[right] == target)
            return right;
        if (left + 1 == right) {
            if (nums[left] == target)
                return left;
            else
                return -1;
        }
        int half = (left + right) / 2;
        if (nums[half] > target)
            right = half;
        else
            left = half;
        return find_right(nums, left, right, target);
    }

public:
    vector<int> searchRange(vector<int> & nums, int target) {
        if (nums.empty() || nums.front() > target || nums.back() < target)
            return {-1, -1};
        return {
            find_left(nums, 0, nums.size() - 1, target),
            find_right(nums, 0, nums.size() - 1, target)
        };
    }
};

int main() {
    Solution sol;
    vector<int> v{5,7,7,8,8,10};
    cout << leetcode::to_string(sol.searchRange(v, 8)) << endl;
    cout << leetcode::to_string(sol.searchRange(v, 6)) << endl;
}
