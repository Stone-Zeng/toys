// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/

#include <iostream>
#include "leetcode_util.h"
using namespace std;
using leetcode::ListNode;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head != nullptr && head->next != nullptr) {
            auto p0 = head, p2 = swapPairs(head->next->next);
            head = p0->next;
            head->next = p0;
            head->next->next = p2;
        }
        return head;
    }
};

int main() {
    Solution sol;
    auto head = new ListNode{1,2,3,4};
    cout << leetcode::to_string(head) << endl;
    head = sol.swapPairs(head);
    cout << leetcode::to_string(head) << endl;
}
