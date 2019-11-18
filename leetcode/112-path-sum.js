/**
 * 112. Path Sum
 * https://leetcode.com/problems/path-sum/
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
 * @param {TreeNode} root
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function(root, sum) {
    if (root === null) return false;
    if (root.left === null && root.right === null) return root.val === sum;
    var nextSum = sum - root.val;
    return hasPathSum(root.left, nextSum) || hasPathSum(root.right, nextSum);
};

var _test = function() {
    var tree = null;
    console.log("1", hasPathSum(tree, 10));

    tree = new TreeNode(3);
    tree.left = new TreeNode(9);
    tree.right = new TreeNode(20);
    tree.left.left = new TreeNode(15);
    tree.left.right = new TreeNode(7);
    console.log("2", hasPathSum(tree, 27));
    console.log("2", hasPathSum(tree, 19));
    console.log("2", hasPathSum(tree, 20));
    console.log("2", hasPathSum(tree, 23));

    tree = new TreeNode(1);
    tree.left = new TreeNode(2);
    tree.right = new TreeNode(2);
    tree.left.left = new TreeNode(3);
    tree.left.right = new TreeNode(3);
    tree.left.left.left = new TreeNode(4);
    tree.left.left.right = new TreeNode(4);
    console.log("3", hasPathSum(tree, 10));
};
_test();
