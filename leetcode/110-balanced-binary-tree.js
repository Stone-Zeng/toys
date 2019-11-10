/**
 * 110. Balanced Binary Tree
 * https://leetcode.com/problems/balanced-binary-tree/
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
 * From #104.
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    if (root === null) return 0;
    return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
};

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function(root) {
    if (root === null) return true;
    return Math.abs(maxDepth(root.left) - maxDepth(root.right)) <= 1
        && isBalanced(root.left)
        && isBalanced(root.right);
};

var _test = function() {
    var tree = null;
    console.log(isBalanced(tree));

    tree = new TreeNode(3);
    tree.left = new TreeNode(9);
    tree.right = new TreeNode(20);
    tree.right.left = new TreeNode(15);
    tree.right.right = new TreeNode(7);
    console.log(isBalanced(tree));

    tree = new TreeNode(1);
    tree.left = new TreeNode(2);
    tree.right = new TreeNode(2);
    tree.left.left = new TreeNode(3);
    tree.left.right = new TreeNode(3);
    tree.left.left.left = new TreeNode(4);
    tree.left.left.right = new TreeNode(4);
    console.log(isBalanced(tree));
};
_test();
