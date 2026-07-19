class Solution {
public:
    int ways(int idx,int n,vector<int>& dp){
        if(idx > n) return 0;
        if(idx == n) return 1;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = ways(idx + 1,n,dp) + ways(idx + 2,n,dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return ways(0,n,dp);
    }
};