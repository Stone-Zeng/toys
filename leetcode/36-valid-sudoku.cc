// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

#include <algorithm>
#include <iostream>
#include <vector>
#include "leetcode_util.h"
using namespace std;

class Solution {
    typedef vector<char> List;
    typedef vector<List> Board;

    const size_t Size = 9;
    const vector<vector<int>> Block_indices = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    inline bool isValid(const List & v) {
        auto result = v;
        result.erase(remove(result.begin(), result.end(), '.'), result.end());
        sort(result.begin(), result.end());
        return unique(result.begin(), result.end()) == result.end();
    }
    inline Board transpose(const Board & board) {
        Board result{Size};
        for (auto i = 0; i != Size; ++i)
            for (auto j = 0; j != Size; ++j)
                result[i].push_back(board[j][i]);
        return result;
    }
    inline Board getBlocks(const Board & board) {
        Board result;
        for (const auto & is : Block_indices)
            for (const auto & js : Block_indices) {
                List temp;
                for (const auto & i : is)
                    for (const auto & j : js)
                        temp.push_back(board[i][j]);
                result.push_back(temp);
            }
        return result;
    }

public:
    bool isValidSudoku(const vector<vector<char>> & board) {
        for (const auto & m : {board, transpose(board), getBlocks(board)})
            for (const auto & list : m)
                if (!isValid(list)) return false;
        return true;
    }
};

int main() {
    Solution sol;
    cout << leetcode::to_string(sol.isValidSudoku({
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    })) << endl;
    cout << leetcode::to_string(sol.isValidSudoku({
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    })) << endl;
}
