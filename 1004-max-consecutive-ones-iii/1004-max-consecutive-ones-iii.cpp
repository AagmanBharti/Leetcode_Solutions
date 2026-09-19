class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes = 0;
        int maxCnt = 0;

        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0) zeroes++;

            while(zeroes > k){
                if(nums[left] == 0) zeroes--;
                left++;
            }

            if(zeroes <= k){
                int cnt = right - left + 1;
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }
};