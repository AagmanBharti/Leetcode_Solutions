class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mpp;
        for(auto it : nums) mpp[it]++;

        for(auto& [num, freq] : mpp){
            if(freq > floor(nums.size()/2)) ans = num;
        }
        return ans;
    }
};