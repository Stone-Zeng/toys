// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

#include <iostream>
#include "leetcode_util.h"
using namespace std;
using leetcode::ListNode;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val)
            head = head->next;
        if (!head) return nullptr;
        auto p = head, prev = head;
        while (p->next) {
            p = p->next;
            if (p->val == val)
                prev->next = p->next;
            else
                prev = p;
        }
        return head;
    }
};

int main() {
    Solution sol;
    for (auto i : {
        new ListNode{1},
        new ListNode{1,1,1},
        new ListNode{1,2},
        new ListNode{1,1,1,3},
        new ListNode{2,1,1,3},
        new ListNode{2,1,1,1},
        new ListNode{2,2,1,1,1},
        new ListNode{2,1,3,1,2,1,1,3},
    }) {
        cout << to_string(i) << ":\t" << to_string(sol.removeElements(i, 1)) << endl;
        delete i;
    }
}
