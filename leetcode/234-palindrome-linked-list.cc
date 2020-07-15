// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

#include <iostream>
#include <vector>
#include "leetcode_util.h"
using namespace std;
using leetcode::ListNode;

class Solution {
public:
    bool isPalindrome(ListNode * head) {
        if (!head || !head->next) return true;
        vector<int> elems;
        while (head->next) {
            elems.push_back(head->val);
            head = head->next;
        }
        elems.push_back(head->val);
        int i = 0, j = elems.size() - 1;
        while (i < j) {
            if (elems[i] != elems[j]) return false;
            ++i; --j;
        }
        return true;
    }
};

int main() {
    Solution sol;
    auto head = new ListNode{};
    cout << sol.isPalindrome(head) << endl;

    head = new ListNode{1};
    cout << sol.isPalindrome(head) << endl;

    head = new ListNode{1,2};
    cout << sol.isPalindrome(head) << endl;

    head = new ListNode{1,2,1};
    cout << sol.isPalindrome(head) << endl;

    head = new ListNode{1,2,2,1};
    cout << sol.isPalindrome(head) << endl;

    head = new ListNode{1,2,2,2};
    cout << sol.isPalindrome(head) << endl;
}
