class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0,zeroes = 0;
        int l = 0,r = 0;
        for(int r=0;r<nums.size();r++){
            if(nums[r] == 0) zeroes++;
            while(zeroes > 1){
                if(nums[l] == 0){
                    zeroes--;
                }
                    l++;
            }
                maxLen = max(r-l,maxLen);
            }
    return maxLen;
    }
};