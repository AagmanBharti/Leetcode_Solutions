class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        int sum = 0;
        vector<int> ans;
        for(int i = nums.size()-1; i >= 0; i--){
            total_sum -= nums[i];
            sum += nums[i];
            ans.push_back(nums[i]);
            if(sum > total_sum) break;
        }
        sort(ans.begin(), ans.end(), std::greater<>());
        return ans;
    }
};