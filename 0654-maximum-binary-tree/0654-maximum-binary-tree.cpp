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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;

        for (int num : nums) {
            TreeNode* curr = new TreeNode(num);

            // Pop smaller elements
            while (!st.empty() && st.top()->val < num) {
                curr->left = st.top();
                st.pop();
            }

            // If stack not empty, current is right child
            if (!st.empty()) {
                st.top()->right = curr;
            }

            st.push(curr);
        }

        // Bottom of stack is root
        while (st.size() > 1) {
            st.pop();
        }

        return st.top();
    }
};
