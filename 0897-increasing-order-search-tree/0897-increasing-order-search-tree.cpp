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

    void inorder(TreeNode* root, vector<int>& nums){
        if(root == NULL) return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);

        TreeNode* head = new TreeNode(nums[0]);
        TreeNode* curr = head;

        for(int i = 1; i < nums.size(); i++){
            curr->right = new TreeNode(nums[i]);
            curr = curr->right;
        }

        return head;
    }
};