/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode inorder(TreeNode root, int val) {
        if (root == null)
            return null;

        if (root.val == val)
            return root;
        TreeNode left = inorder(root.left, val);
        if (left != null)
            return left;

        return inorder(root.right, val);
    }

    public TreeNode searchBST(TreeNode root, int val) {
        return inorder(root, val);
    }
}