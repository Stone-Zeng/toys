// 18. 4Sum
// https://leetcode.com/problems/4sum/

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// https://stackoverflow.com/a/29855973
class VectorHash {
public:
    size_t operator()(const vector<int>& v) const {
        hash<int> hasher;
        size_t seed = 0;
        for (int i : v)
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        return seed;
    }
};

class Solution {
public:
    void preprocess(vector<int> & nums) {
        sort(nums.begin(), nums.end());
        auto iter = nums.begin();
        auto temp = nums[0];
        auto count = 0;
        while (iter != nums.end()) {
            if (*iter == temp)
                count++;
            else
                count = 0;
            temp = *iter;
            if (count > 4)
                iter = nums.erase(iter);
            else
                iter++;
        }
    }

    vector<vector<int>> fourSum(vector<int> & nums, int target) {
        if (nums.size() < 4)
            return {};

        preprocess(nums);
        auto nums_size = nums.size();
        if (nums[0] + nums[1] + nums[2] + nums[3] > target ||
            nums[nums_size - 1] + nums[nums_size - 2] + nums[nums_size - 3] + nums[nums_size - 4] < target)
            return {};

        vector<int> temp(4);
        unordered_set<vector<int>, VectorHash> result_set;
        const auto nums_end = nums.end();
        for (auto i = nums.begin(); i != nums_end - 3; ++i) {
            const auto x_i = *i;
            for (auto j = i + 1; j != nums_end - 2; ++j) {
                const auto x_j = *j;
                for (auto k = j + 1; k != nums_end - 1; ++k) {
                    auto x_k = *k, x_l = target - x_i - x_j - x_k;
                    if (x_l >= x_k && binary_search(k + 1, nums_end, x_l)) {
                        temp = {x_i, x_j, x_k, x_l};
                        if (result_set.find(temp) == result_set.end())
                            result_set.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> result;
        for (const auto & i: result_set) {
            result.push_back(i);
        }
        return result;
    }
};

template<typename T>
void _print_vec2(const vector<vector<T>> & v) {
    for (const auto & i: v) {
        cout << "[";
        for (const auto & j: i)
            cout << j << ", ";
        cout << "]" << endl;
    }
}

int main() {
    vector<int> v;
    Solution sol;

    v = {1,0,-1,0,-2,2};
    _print_vec2(sol.fourSum(v, 0));
    cout << endl;

    v = {12,13,-10,-15,4,5,-8,11,10,3,-11,4,-10,4,-7,9,1,8,-5,-1,-9,-4,3,-14,-11,14,0,-8,-6,-2,14,-9,-4,11,-8,-14,-7,-9,4,10,9,9,-1,7,-10,7,1,6,-8,12,12,-10,-7,0,-9,-3,-1,-1,-4,8,12,-13,6,-7,13,5,-14,13,12,6,8,-2,-8,-15,-10,-3,-1,7,10,7,-4,7,4,-4,14,3,0,-10,-13,11,5,6,13,-4,6,3,-13,8,1,6,-9,-14,-11,-10,8,-5,-6,-7,9,-11,7,12,3,-4,-7,-6,14,8,-1,8,-4,-11};
    _print_vec2(sol.fourSum(v, 24));
}
