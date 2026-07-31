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
    int minimum;
    long secondMin = LONG_MAX;

    void dfs(TreeNode* root){
        if(root == NULL) return;
        if(root->val > minimum){
            secondMin = min(secondMin, (long)root->val);
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        minimum = root->val;
        dfs(root);
        return secondMin == LONG_MAX ? -1 : secondMin;
    }
};