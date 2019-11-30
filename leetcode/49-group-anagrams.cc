// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "leetcode_util.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> & strs) {
        unordered_map<string, vector<string>> map;
        for (const auto & str : strs) {
            auto s{str};
            sort(s.begin(), s.end());
            map[s].push_back(str);
        }
        decltype(groupAnagrams(strs)) result;
        for (const auto & val : map)
            result.push_back(val.second);
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> data = {
        {"eat", "tea", "tan", "ate", "nat", "bat"},
        {},
        {"","",""},
    };
    for (auto & i : data)
        cout << leetcode::to_string(sol.groupAnagrams(i)) << endl;;
}
