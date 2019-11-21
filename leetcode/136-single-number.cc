// 136. Single Number
// https://leetcode.com/problems/single-number/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> & nums) {
        unordered_set<int> s;
        for (auto & n : nums) {
            auto iter = s.find(n);
            if (iter == s.end())
                s.insert(n);
            else
                s.erase(iter);
        }
        return *s.begin();
    }
};

int main() {
    vector<vector<int>> v{
        {2,2,1},
        {4,1,2,1,2},
        {9,21,16,48,41,5,8,24,2,7,1,1,13,23,26,48,10,11,45,38,40,44,15,47,28,3,44,46,21,36,14,49,9,10,37,36,38,3,31,12,2,47,8,39,35,39,4,43,49,22,18,15,50,41,14,32,25,27,43,25,20,700,7,30,12,37,11,16,45,19,17,42,6,30,19,32,6,31,22,28,50,5,46,34,34,13,4,42,17,24,35,29,33,18,20,29,26,27,23,33,40},
    };
    Solution sol;
    for (auto & i : v)
        cout << sol.singleNumber(i) << endl;
}
