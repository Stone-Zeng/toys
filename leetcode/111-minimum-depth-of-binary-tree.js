/**
 * 111. Minimum Depth of Binary Tree
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
 * @return {number}
 */
var minDepth = function(root) {
    if (root === null) return 0;
    if (root.left === null) {
        if (root.right === null) return 1;
        return 1 + minDepth(root.right);
    } else {
        if (root.right === null) return 1 + minDepth(root.left);
        return 1 + Math.min(minDepth(root.left), minDepth(root.right));
    }
};

var _test = function() {
    var tree = null;
    console.log(minDepth(tree));

    tree = new TreeNode(3);
    tree.left = new TreeNode(9);
    tree.right = new TreeNode(20);
    tree.right.left = new TreeNode(15);
    tree.right.right = new TreeNode(7);
    console.log(minDepth(tree));

    tree = new TreeNode(1);
    tree.left = new TreeNode(2);
    tree.right = new TreeNode(2);
    tree.left.left = new TreeNode(3);
    tree.left.right = new TreeNode(3);
    tree.left.left.left = new TreeNode(4);
    tree.left.left.right = new TreeNode(4);
    console.log(minDepth(tree));
};
_test();
