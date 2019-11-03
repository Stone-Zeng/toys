/**
 * 107. Binary Tree Level Order Traversal II
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
 * @return {number[][]}
 */
var levelOrderBottom = function(root) {
    if (root === null) return [];
    return getTrees([root]).map(trees => trees.map(tree => tree.val));
};

/**
 * @param {TreeNode[]} trees
 * @return {TreeNode[][]}
 */
var getTrees = function(trees) {
    var nextLevel = [];
    for (var tree of trees) {
        if (tree.left === null) {
            if (tree.right !== null)
                nextLevel.push(tree.right);
        } else {
            if (tree.right !== null)
                nextLevel.push(tree.left, tree.right);
            else
                nextLevel.push(tree.left);
        }
    }
    if (nextLevel.length === 0) return [trees];
    return getTrees(nextLevel).concat([trees]);
};

var _test = function() {
    var tree = new TreeNode(1);
    // console.log(getTrees([tree]));
    console.log(levelOrderBottom(tree));

    tree = new TreeNode(1);
    tree.left = new TreeNode(2);
    tree.right = new TreeNode(3);
    // console.log(getTrees([tree]));
    console.log(levelOrderBottom(tree));

    tree = new TreeNode(3);
    tree.left = new TreeNode(9);
    tree.right = new TreeNode(20);
    tree.right.left = new TreeNode(15);
    tree.right.right = new TreeNode(7);
    // console.log(getTrees([tree]));
    console.log(levelOrderBottom(tree));

    tree = new TreeNode(3);
    tree.left = new TreeNode(9);
    tree.right = new TreeNode(20);
    tree.right.left = new TreeNode(15);
    tree.right.right = new TreeNode(7);
    tree.right.right.left = new TreeNode(15);
    tree.right.right.right = new TreeNode(7);
    console.log(levelOrderBottom(tree))
    // console.log(getTrees([tree]));
    for (var i = 0; i !== 100000; ++i)
        levelOrderBottom(tree);
};
_test();
