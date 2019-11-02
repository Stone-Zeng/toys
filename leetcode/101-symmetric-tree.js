/**
 * 101. Symmetric Tree
 * https://leetcode.com/problems/symmetric-tree/
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
 * @return {boolean}
 */
var isSymmetric = function(root) {
    if (root === null) return true;
    return isMirrored(root.left, root.right);
};

/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isMirrored = function(p, q) {
    if (p === null) {
        if (q === null) return true;
        return false;
    }
    if (q === null) return false;
    return p.val === q.val && isMirrored(p.left, q.right) && isMirrored(p.right, q.left);
};

var _test = function() {
    var tree = new TreeNode(1);
    tree.left = new TreeNode(2);
    tree.right = new TreeNode(3);
    console.log(isSymmetric(tree));

    tree = new TreeNode(1);
    tree.left = new TreeNode(2);
    tree.right = new TreeNode(2);
    tree.left.left = new TreeNode(3);
    tree.left.right = new TreeNode(4);
    tree.right.left = new TreeNode(4);
    tree.right.right = new TreeNode(3);
    console.log(isSymmetric(tree));
};
_test();
