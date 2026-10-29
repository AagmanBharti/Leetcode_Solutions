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
    unordered_map<int, TreeNode*> mp;

    bool dfs(TreeNode* root, long long low, long long high) {
        if (!root)
            return true;

        if (root->val <= low || root->val >= high)
            return false;

        // If this is a leaf matching another tree's root,
        // merge that tree here.
        if (!root->left && !root->right && mp.count(root->val)) {
            root->left = mp[root->val]->left;
            root->right = mp[root->val]->right;
            mp.erase(root->val);
        }

        return dfs(root->left, low, root->val) &&
               dfs(root->right, root->val, high);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_set<int> leaves;

        for (TreeNode* root : trees) {
            mp[root->val] = root;

            if (root->left)
                leaves.insert(root->left->val);

            if (root->right)
                leaves.insert(root->right->val);
        }

        TreeNode* root = nullptr;

        for (TreeNode* tree : trees) {
            if (!leaves.count(tree->val)) {
                if (root != nullptr)
                    return nullptr;

                root = tree;
            }
        }

        if (root == nullptr)
            return nullptr;

        // The final root should not be merged into another tree.
        mp.erase(root->val);

        if (!dfs(root, LLONG_MIN, LLONG_MAX))
            return nullptr;

        if (!mp.empty())
            return nullptr;

        return root;
    }
};
