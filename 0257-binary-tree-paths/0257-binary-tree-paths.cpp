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

    void solve(TreeNode* root,string result,vector<string> &ans){
        if(!root->left && !root->right){
            result+= to_string(root->val);
            ans.push_back(result);
            return;
        }

        int x = root->val;
        result+= to_string(x);
        result+= "->";
        if(root->left) solve(root->left,result,ans);
        if(root->right) solve(root->right,result,ans);
        result.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string result;
        solve(root,result,ans);
        return ans;
    }
};