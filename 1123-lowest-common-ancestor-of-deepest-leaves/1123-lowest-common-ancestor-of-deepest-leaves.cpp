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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int a = height(root->left);
        int b = height(root->right);
        return a > b ? a+1 : b+1;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL) return NULL;

        TreeNode* x = lcaDeepestLeaves(root->left);
        TreeNode* y = lcaDeepestLeaves(root->right);

        if(x == NULL && y == NULL) return root;
        else if(x == NULL) return y;
        else if(y == NULL) return x;
        else {
            int e = height(root->left);
            int f = height(root->right);
            if(e > f) return x;
            else if(f > e) return y;
            else return root;
        } 
    }
};