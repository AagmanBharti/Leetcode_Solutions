/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int row, int col,
             map<int, map<int, vector<int>>>& mp) {

        if (root == nullptr)
            return;

        mp[col][row].push_back(root->val);

        dfs(root->left, row + 1, col - 1, mp);

        dfs(root->right, row + 1, col + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;

        map<int, map<int, vector<int>>> mp;

        dfs(root, 0, 0, mp);

        for (auto& [col, rows] : mp) {

            vector<int> temp;

            for (auto& [row, values] : rows) {

                sort(values.begin(), values.end());

                for (int value : values) {
                    temp.push_back(value);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};