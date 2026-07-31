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

    bool dfs(TreeNode* root){
        if(root == NULL) return true;
        bool leftValid = dfs(root->left);
        bool rightValid = dfs(root->right);
        if(!leftValid || !rightValid) return false;
        if(root->left != NULL && root->val != root->left->val) return false;
        if(root->right != NULL && root->val != root->right->val) return false;
        return true;
    }

    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        return dfs(root);
    }
};