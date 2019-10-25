// 67. Add Binary
// https://leetcode.com/problems/add-binary/

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    // Assume a.length() >= b.length()
    string _addBinary(string a, string b) {
        char flag = '0';
        auto ia = a.rbegin();
        for (auto ib = b.rbegin(); ib != b.rend(); ++ib) {
            if (flag == '0') {
                if (*ia == '0') {
                    // (flag = 0; a = 0, b = 0) -> (flag = 0; a = 0, b)
                    // (flag = 0; a = 0, b = 1) -> (flag = 0; a = 1, b)
                    *ia = *ib;
                } else if (*ib == '1') {
                    // (flag = 0; a = 1, b = 1) -> (flag = 1; a = 0, b)
                    *ia = '0';
                    flag = '1';
                }
                // (flag = 0; a = 1, b = 0) -> (flag = 0; a = 1, b)
                // Do nothing
            } else {
                if (*ia == '0') {
                    // (flag = 1; a = 0, b = 0) -> (flag = 0; a = 1, b)
                    // (flag = 1; a = 0, b = 1) -> (flag = 1; a = 0, b)
                    *ia = (*ib == '0') ? '1' : '0';
                    flag = *ib;
                } else {
                    // (flag = 1; a = 1, b = 0) -> (flag = 1; a = 0, b)
                    // (flag = 1; a = 1, b = 1) -> (flag = 1; a = 1, b)
                    *ia = *ib;
                    flag = '1';
                }
            }
            ++ia;
        }
        if (flag == '0') return a;
        for (; ia != a.rend(); ++ia) {
            if (flag == '0') return a;
            if (*ia == '0') {
                *ia = '1';
                return a;
            } else {
                *ia = '0';
                flag = '1';
            }
        }
        return '1' + a;
    }
public:
    string addBinary(string a, string b) {
        return (a.length() >= b.length()) ? _addBinary(a, b) : _addBinary(b, a);
    }
};

int main() {
    Solution sol;
    cout << sol.addBinary("11", "1") << endl;
    cout << sol.addBinary("1010", "1011") << endl;
    cout << sol.addBinary("101111", "10") << endl;
    cout << sol.addBinary(
        "1010011100000110110010110111100101001111",
        "10100111000001101100101101111001010100111") << endl;
}
