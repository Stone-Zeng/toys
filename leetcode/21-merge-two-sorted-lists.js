/**
 * 21. Merge Two Sorted Lists
 * https://leetcode.com/problems/merge-two-sorted-lists/
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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    if (l1 === null) return l2;
    if (l2 === null) return l1;
    if (l1.val < l2.val) {
        var result = new ListNode(l1.val);
        result.next = mergeTwoLists(l1.next, l2);
        return result;
    } else {
        var result = new ListNode(l2.val);
        result.next = mergeTwoLists(l2.next, l1);
        return result;
    }
};

var _test = function() {
    var x = new ListNode(1);
    x.next = new ListNode(2);
    x.next.next = new ListNode(4);

    var y = new ListNode(1);
    y.next = new ListNode(3);
    y.next.next = new ListNode(4);

    console.log(x);
    console.log(y);
    console.log(mergeTwoLists(x, y));
};
_test();
