// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    inline string sanitize(string & s) {
        string result;
        for (auto & c : s)
            if (isalnum(c)) {
                if (isupper(c)) c = tolower(c);
                result.push_back(c);
            }
        return result;
    }
    bool isPalindrome(string s) {
        s = sanitize(s);
        auto len = s.length();
        for (auto i = 0; i != len / 2; i++)
            if (s[i] != s[len - i - 1]) return false;
        return true;
    }
};

int main() {
    vector<string> v{"", "a", "0p", "Bb", "Ba", "aba", "ABa", "A man, a plan, a canal: Panama", "race a car"};
    Solution sol;
    for (auto &s : v)
        cout << "\"" + s + "\"\t" << sol.sanitize(s) << "\t" << sol.isPalindrome(s) << endl;
}
