// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * getIntersectionNode(struct ListNode * headA, struct ListNode * headB) {
    if (headA == NULL || headB == NULL)
        return NULL;
    struct ListNode * headB_clone;
    while (headA != NULL) {
        headB_clone = headB;
        while (headB_clone != NULL) {
            if (headA == headB_clone)
                return headA;
            headB_clone = headB_clone->next;
        }
        headA = headA->next;
    }
    return NULL;
}
