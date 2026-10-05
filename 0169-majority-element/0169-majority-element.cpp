class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int ans = 0;

        for(auto num : nums){
            mpp[num]++;
        }

        for(auto& [num, freq] : mpp){
            if(freq > floor(nums.size()/2)) ans = num;
        }
        return ans;
    }
};