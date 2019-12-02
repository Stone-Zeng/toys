// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <iostream>
#include "leetcode_util.h"
using namespace std;
using leetcode::ListNode;

class Solution {
    inline int listNodeLength(ListNode * head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }

public:
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        if (n <= 0) return head;
        const int len = listNodeLength(head);
        if (n >= len) return head->next;
        auto new_head = head;
        for (int i = 0; i != len - n - 1; ++i)
            head = head->next;
        head->next = head->next->next;
        return new_head;
    }
};

int main() {
    Solution sol;

    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << leetcode::to_string(head) << endl;
    head = sol.removeNthFromEnd(head, 2);
    cout << leetcode::to_string(head) << endl;
}
