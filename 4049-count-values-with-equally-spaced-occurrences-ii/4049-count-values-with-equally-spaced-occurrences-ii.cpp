class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> freq;

        // Store indices of each number
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]].push_back(i);

        int ans = 0;

        for (const auto& [key, val] : freq) {
            if (val.size() < 3)
                continue;

            int diff = val[1] - val[0];
            bool valid = true;

            for (int i = 2; i < val.size(); i++) {
                if (val[i] - val[i - 1] != diff) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans++;
        }

        return ans;
    }
};