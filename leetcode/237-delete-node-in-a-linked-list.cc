// 237. Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <iostream>
#include "leetcode_util.h"
using namespace std;
using leetcode::ListNode;

class Solution {
public:
    void deleteNode(ListNode* node) {
        // while (node->next->next) {
        //     node->val = node->next->val;
        //     node = node->next;
        // }
        // node->val = node->next->val;
        // node->next = nullptr;

        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    Solution sol;
    auto head = new ListNode{4,5,1,9};
    sol.deleteNode(head->next);
    cout << to_string(head) << endl;

    head = new ListNode{4,5,1,9,7,0,12,13};
    sol.deleteNode(head);
    cout << to_string(head) << endl;

    head = new ListNode{4,5};
    sol.deleteNode(head);
    cout << to_string(head) << endl;
}
