// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/

#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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

    auto head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next;
    printListNode(head1);
    cout << boolalpha << sol.hasCycle(head1) << endl;
    delete head1->next->next->next;
    delete head1->next->next;
    delete head1->next;
    delete head1;

    auto head2 = new ListNode(3);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(0);
    printListNode(head2);
    cout << boolalpha << sol.hasCycle(head2) << endl;
    delete head2->next->next->next;
    delete head2->next->next;
    delete head2->next;
    delete head2;

    auto head3 = new ListNode(1);
    head3->next = head3;
    printListNode(head3);
    cout << boolalpha << sol.hasCycle(head3) << endl;
    delete head3;

    auto head4 = nullptr;
    printListNode(head4);
    cout << boolalpha << sol.hasCycle(head4) << endl;
}
