/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* node){
        if(node == NULL) return 0;
        int lH = height(node->left);
        if(lH == -1) return -1;
        int rH = height(node->right);
        if(rH == -1) return -1;
        if(abs(lH - rH) > 1) return -1;
        return 1 + max(lH,rH);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};