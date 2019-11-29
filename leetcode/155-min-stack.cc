// 155. Min Stack
// https://leetcode.com/problems/min-stack/

#include <iostream>
using namespace std;

class MinStack {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode *head;
    ListNode *p;

public:
    MinStack() : head(new ListNode(0)), p(head) {}

    void push(int x) {
        p->next = new ListNode(x);
        p = p->next;
    }

    void pop() {
        auto i = head;
        while (i->next != p) i = i->next;
        delete p;
        i->next = nullptr;
        p = i;
    }

    int top() {
        return p->val;
    }

    int getMin() {
        auto i = head->next;
        auto min = i->val;
        while (i->next) {
            i = i->next;
            min = (min < i->val) ? min : i->val;
        }
        return min;
    }
};

int main() {
    MinStack *obj1 = new MinStack();
    obj1->push(-2);
    obj1->push(0);
    obj1->push(-4);
    obj1->push(-5);
    obj1->push(2);
    cout << obj1->top() << endl;
    obj1->pop();
    cout << obj1->top() << endl;
    obj1->pop();
    cout << obj1->top() << endl;
    cout << obj1->getMin() << endl;

    MinStack *obj2 = new MinStack();
    obj2->push(2147483646);
    obj2->push(2147483646);
    obj2->push(2147483647);
    cout << obj2->top() << endl;
    obj2->pop();
    cout << obj2->getMin() << endl;
    obj2->pop();
    cout << obj2->getMin() << endl;
    obj2->pop();
    obj2->push(2147483647);
    cout << obj2->top() << endl;
    cout << obj2->getMin() << endl;
    obj2->push(-2147483648);
    cout << obj2->top() << endl;
    cout << obj2->getMin() << endl;
    obj2->pop();
    cout << obj2->getMin() << endl;
}
