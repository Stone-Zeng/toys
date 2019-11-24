// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> & prices) {
        int profit = 0, size = prices.size();
        for (auto i = 0; i < size - 1; ++i) {
            auto delta = prices[i + 1] - prices[i];
            if (delta > 0) profit += delta;
        }
        return profit;
    }
};

int main() {
    vector<vector<int>> prices {
        {},
        {0},
        {1,2,3,4,5},
        {5,4,3,2,1},
        {7,1,5,3,6,4},
        {7,6,4,3,1},
        {44,79,54,91,69,15,22,18,60,76,9,86,42,16,36,76,29,25,13,4,20,17,21,73,3,32,2,53,39,68,59,77,96,47,58,73,8,5,73,35,88,4,6,63,97,70,27,87,42,1,86,93,74,23,64,39,50,81,9,68,98,55,64,49,89,37,6,85,46,44,7,41,28,65,43,62,42,97,54,59,79,54,30,20,52,68,86,42,10,90,26,30,24,55,20,87,22,38,20,54,31,70,62,11,90,22,42,14,5,46,21,6,75,22,77,26,84,99,54,83,29,28,4,20,13,44,75,99,86,43,15,69,51,19,74,20,76,76,4,63,45,98,64,44,88,36,60,43,31,49,80,84,39,98,35,43,8,86,48,66,34,62,55,57,21,66,20,43,98,83,9,33,66,75,55,65,44,18,41,35,55,63,21,53,30,88,67,4,90,6,69,29,90,40,63,73,99,29,69,79},
    };
    Solution sol;
    for (auto i: prices)
        cout << sol.maxProfit(i) << ", ";
    cout << endl;
}
