/**
 * 2. Add Two Numbers
 * https://leetcode.com/problems/add-two-numbers/
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
var addTwoNumbers = function(l1, l2) {
    return _addTwoNumbers(l1, l2, 0);
};

var _addTwoNumbers = function(l1, l2, flag) {
    if (l1 === null) {
        if (l2 === null) {
            if (flag === 0) return null;
            return new ListNode(1);
        }
        return _addNumber(l2, flag);
    }
    if (l2 === null) return _addNumber(l1, flag);

    if (l1.val + l2.val + flag <= 9) {
        var result = new ListNode(l1.val + l2.val + flag);
        result.next = _addTwoNumbers(l1.next, l2.next, 0);
        return result;
    }
    var result = new ListNode(l1.val + l2.val + flag - 10);
    result.next = _addTwoNumbers(l1.next, l2.next, 1);
    return result;
}

var _addNumber = function(list, flag) {
    if (flag === 1) {
        if (list.val < 9) {
            list.val += 1;
            return list;
        }
        if (list.next === null) {
            [list.val, list.next] = [0, new ListNode(1)];
            return list;
        }
        [list.val, list.next] = [0, _addNumber(list.next, 1)];
        return list;
    }
    return list;
}

var _show = function(list) {
    if (list === null) return null;
    var [result, i] = [list.val, list.next];
    while (i !== null) {
        result += " -> " + i.val;
        i = i.next;
    }
    return result;
}
var _test = function() {
    var x = null;
    var y = null;
    console.log(`${_show(x)}, ${_show(y)}, ${_show(addTwoNumbers(x, y))}`);

    var x = new ListNode(4);
    var y = new ListNode(5);
    console.log(`${_show(x)}, ${_show(y)}, ${_show(addTwoNumbers(x, y))}`);

    var x = new ListNode(2); x.next = new ListNode(4); x.next.next = new ListNode(3);
    var y = new ListNode(5); y.next = new ListNode(6); y.next.next = new ListNode(4);
    console.log(`${_show(x)}, ${_show(y)}, ${_show(addTwoNumbers(x, y))}`);

    var x = new ListNode(1); x.next = new ListNode(9);
    var y = new ListNode(1); y.next = new ListNode(1);
    console.log(`${_show(x)}, ${_show(y)}, ${_show(addTwoNumbers(x, y))}`);

    var x = new ListNode(1); x.next = new ListNode(9); x.next.next = new ListNode(3);
    var y = new ListNode(1); y.next = new ListNode(1);
    console.log(`${_show(x)}, ${_show(y)}, ${_show(addTwoNumbers(x, y))}`);

    var x = new ListNode(0);
    var y = new ListNode(0); y.next = new ListNode(1);
    console.log(`${_show(x)}, ${_show(y)}, ${_show(addTwoNumbers(x, y))}`);

    var x = new ListNode(9);
    var y = new ListNode(9); y.next = new ListNode(9); y.next.next = new ListNode(9); y.next.next.next = new ListNode(9);
    console.log(`${_show(x)}, ${_show(y)}, ${_show(addTwoNumbers(x, y))}`);
};
_test();
