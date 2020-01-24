// 168. Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) return "";
        return convertToTitle((n - 1) / 26) + string(1, 65 + (n - 1) % 26);
    }
};

int main() {
    Solution sol;
    auto data = {0, 1, 12, 26, 27, 51, 52, 53, 388, 1000, 10000};
    for (const auto i : data)
        cout << i << " -> " << sol.convertToTitle(i) << endl;
}
