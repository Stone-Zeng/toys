// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<size_t> vowel_indices;
        vector<char> vowels;
        for (size_t i = 0; i != s.size(); ++i) {
            auto c = s[i];
            if (isVowel(c)) {
                vowel_indices.push_back(i);
                vowels.push_back(c);
            }
        }
        for (size_t i = 0; i != vowel_indices.size(); ++i) {
            s[vowel_indices[vowel_indices.size() - i - 1]] = vowels[i];
        }
        return s;
    }

private:
    inline bool isVowel(char c) {
        switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
        }
    }
};

int main() {
    Solution sol;
    for (auto s: {"hello", "", "leetcode", "eE"})
        std::printf("\"%s\" => \"%s\"\n", s, sol.reverseVowels(s).c_str());
    return 0;
}
