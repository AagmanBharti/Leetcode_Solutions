class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        vector<int> zeroes(n, 0);

        if(nums == zeroes) return 0;

        int xr = 0;
        for(int num : nums){
            xr ^= num;
        }

        return xr ? n : n-1;
    }
};