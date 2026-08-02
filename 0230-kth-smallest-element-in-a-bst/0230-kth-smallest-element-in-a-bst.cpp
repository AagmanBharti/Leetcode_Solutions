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
    void inorder(TreeNode* root, int& counter, int k, int& kSmallest){
        if(!root || counter >= k) return;
        inorder(root->left, counter, k, kSmallest);
        counter++;
        if(counter == k){
            kSmallest = root->val;
            return;
        }
        inorder(root->right, counter, k, kSmallest);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int kSmallest = INT_MAX;
        inorder(root, counter, k, kSmallest);
        return kSmallest;
    }
};