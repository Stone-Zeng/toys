/**
 * 83. Remove Duplicates from Sorted List
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 */

/**
 * Definition for singly-linked list.
 * @param {number} val
 */
function ListNode(val) {
    this.val = val;
    this.next = null;
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    if (head !== null && head.next !== null) {
        if (head.val === head.next.val)
            head = deleteDuplicates(head.next);
        else
            head.next = deleteDuplicates(head.next);
    }
    return head;
};

var _test = function() {
    console.log(deleteDuplicates(null));

    var x = new ListNode(1);
    console.log(deleteDuplicates(x));

    x = new ListNode(1);
    x.next = new ListNode(1);
    console.log(deleteDuplicates(x));

    x = new ListNode(1);
    x.next = new ListNode(2);
    console.log(deleteDuplicates(x));

    x = new ListNode(1);
    x.next = new ListNode(1);
    x.next.next = new ListNode(1);
    console.log(deleteDuplicates(x));

    x = new ListNode(1);
    x.next = new ListNode(2);
    x.next.next = new ListNode(2);
    console.log(deleteDuplicates(x));

    x = new ListNode(1);
    x.next = new ListNode(2);
    x.next.next = new ListNode(3);
    console.log(deleteDuplicates(x));
};
_test();
