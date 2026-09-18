class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        set<vector<int>> st;

        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == target) {
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target)
                    j++;
                else
                    k--;
            }
        }

        for (auto triplets : st) {
            res.push_back(triplets);
        }

        return res;
    }
};