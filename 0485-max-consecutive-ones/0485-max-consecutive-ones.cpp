class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int cnt = 0;
       int maxCnt = 0;
       int n = nums.size();
       for(int i=0;i<n;i++){
        if(nums[i] == 1)
            cnt++;
        if(nums[i] == 0)
            cnt = 0;
        maxCnt = max(cnt,maxCnt);
       }
       return maxCnt; 
    }
};