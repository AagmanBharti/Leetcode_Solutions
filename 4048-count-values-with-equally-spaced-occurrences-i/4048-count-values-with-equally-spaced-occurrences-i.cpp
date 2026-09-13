class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> freq;

        // Store occurrence indices
        for (int i = 0; i < n; i++) {
            freq[nums[i]].push_back(i);
        }

        int ans = 0;

        // Check each distinct integer
        for (const auto& [key, val] : freq) {
            if (val.size() == 3) {
                if (abs(val[1] - val[0]) == abs(val[2] - val[1])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};