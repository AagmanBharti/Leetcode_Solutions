class Solution {
public:
int helper(int idx, int target, vector<int>&nums,vector<vector<int>>&dp)
    {
        if(target==0) return 0;
        if(idx>= nums.size())
        {
            return 0;
        }
        if(dp[idx][target] != -1) return dp[idx][target]; 
        int pick = 0;
        int notPick = 0;

        if(target >= nums[idx])
        {
            int temp = helper(idx+1, target-nums[idx], nums,dp);

            pick = nums[idx] + temp;
        }
        notPick = helper(idx+1,target,nums,dp);

        return dp[idx][target] =  max(pick,notPick);

    }

    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = accumulate(stones.begin(),stones.end(),0);
        int sum = totalSum / 2;
        vector<vector<int>> dp(stones.size()+1, vector<int>(sum+1,-1));
        int maxSum = helper(0,sum,stones,dp);

        return totalSum - 2*maxSum;
    }
};