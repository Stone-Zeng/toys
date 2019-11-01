// 15. 3Sum
// https://leetcode.com/problems/3sum/

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
            if (count > 3)
                iter = nums.erase(iter);
            else
                iter++;
        }
    }

    vector<vector<int>> threeSum(vector<int> & nums) {
        if (nums.size() < 3)
            return {};

        preprocess(nums);

        vector<int> temp(3);
        unordered_set<vector<int>, VectorHash> result_set;
        const auto nums_end = nums.end();
        for (auto i = nums.begin(); i != nums_end - 2; ++i)
            for (auto j = i + 1; j != nums_end - 1; ++j) {
                const auto x_i = *i, x_j = *j, x_k = - x_i - x_j;
                if (x_k >= x_j && binary_search(j + 1, nums_end, x_k)) {
                    temp = {x_i, x_j, x_k};
                    if (result_set.find(temp) == result_set.end())
                        result_set.insert(temp);
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
    vector<vector<int>> data = {
        {1,-1,0},
        {0,0,0},
        {-1,0,1,2,-1,-4},
        {1,2,-3,4},
        {1,2,-3,9},
        {9,9,-9,9,0},
        {0},
        {29,16,92,56,25,62,59,31,-52,-57,100,-68,-33,-93,-77,31,7,-44,-52,-30,-72,71,16,-68,-1,67,-58,21,-7,-90,-67,59,-38,-19,13,70,37,16,-86,25,-20,87,61,80,16,33,-50,48,-44,9},
        {0,7,-4,-7,0,14,-6,-4,-12,11,4,9,7,4,-10,8,10,5,4,14,6,0,-9,5,6,6,-11,1,-8,-1,2,-1,13,5,-1,-2,4,9,9,-1,-3,-1,-7,11,10,-2,-4,5,10,-15,-4,-6,-8,2,14,13,-7,11,-9,-8,-13,0,-1,-15,-10,13,-2,1,-1,-15,7,3,-9,7,-1,-14,-10,2,6,8,-6,-12,-13,1,-3,8,-9,-2,4,-2,-3,6,5,11,6,11,10,12,-11,-14},
        {12,13,-10,-15,4,5,-8,11,10,3,-11,4,-10,4,-7,9,1,8,-5,-1,-9,-4,3,-14,-11,14,0,-8,-6,-2,14,-9,-4,11,-8,-14,-7,-9,4,10,9,9,-1,7,-10,7,1,6,-8,12,12,-10,-7,0,-9,-3,-1,-1,-4,8,12,-13,6,-7,13,5,-14,13,12,6,8,-2,-8,-15,-10,-3,-1,7,10,7,-4,7,4,-4,14,3,0,-10,-13,11,5,6,13,-4,6,3,-13,8,1,6,-9,-14,-11,-10,8,-5,-6,-7,9,-11,7,12,3,-4,-7,-6,14,8,-1,8,-4,-11},
    };
    Solution sol;
    for (auto v: data) {
        _print_vec2(sol.threeSum(v));
        cout << endl;
    }
}
