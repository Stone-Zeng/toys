/**
 * 108. Convert Sorted Array to Binary Search Tree
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 */

/**
 * Definition for a binary tree node.
 * @param {number} val
 */
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
    if (nums.length ===  0) return null;
    if (nums.length ===  1) return new TreeNode(nums[0]);
    var top_pos = Math.floor(nums.length / 2);
    var tree = new TreeNode(nums[top_pos]);
    tree.left = sortedArrayToBST(nums.slice(0, top_pos));
    tree.right = sortedArrayToBST(nums.slice(top_pos + 1));
    return tree;
};

var _test = function() {
    console.log(sortedArrayToBST([]));
    console.log(sortedArrayToBST([1,2]));
    console.log(sortedArrayToBST([1,2,3]));
    console.log(sortedArrayToBST([1,2,3,4]));
    console.log(sortedArrayToBST([1,2,3,4,5]));
    console.log(sortedArrayToBST([1,2,3,4,5,6]));
};
_test();
