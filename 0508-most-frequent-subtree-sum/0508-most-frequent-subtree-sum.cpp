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
    unordered_map<int, int> freq;

    int subtreeSum(TreeNode* node){
        if(node == nullptr) return 0;

        int leftSum = subtreeSum(node->left);
        int rightSum = subtreeSum(node->right);

        int total = node->val + leftSum + rightSum;
        freq[total]++;
        return total;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        subtreeSum(root);
        int maxfreq = 0;
        for(auto it : freq){
            if(it.second > maxfreq) maxfreq = it.second;
        }

        vector<int> result;
        for(auto it : freq){
            if(it.second == maxfreq){
                result.push_back(it.first);
            }
        }
        return result;
    }
};