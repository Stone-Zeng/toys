// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/

#include <iostream>
#include <unordered_set>
#include "leetcode_util.h"
using namespace std;
using leetcode::ListNode;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<decltype(head)> nodes;
        while (head) {
            if (nodes.find(head) != nodes.end())
                return true;
            else {
                nodes.insert(head);
                head = head->next;
            }
        }
        return false;
    }
};

void printListNode(const ListNode* head, int len=10) {
    auto j = 0;
    for (auto i = head; i != nullptr && j < len; i = i->next) {
        cout << i->val << ", ";
        ++j;
    }
    cout << endl;
}

int main() {
    Solution sol;

    auto head = new ListNode{3,2,0,-4};
    head->next->next->next->next = head->next;
    printListNode(head);
    cout << boolalpha << sol.hasCycle(head) << endl;

    head = new ListNode{3,2,0};
    printListNode(head);
    cout << boolalpha << sol.hasCycle(head) << endl;

    head = new ListNode(1);
    head->next = head;
    printListNode(head);
    cout << boolalpha << sol.hasCycle(head) << endl;

    head = nullptr;
    printListNode(head);
    cout << boolalpha << sol.hasCycle(head) << endl;
}
