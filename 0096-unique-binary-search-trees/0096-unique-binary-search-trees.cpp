class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;

        for(int root = 1;root <= n; root++){
            ans += solve(root-1, dp) * solve(n-root, dp);
        }

        return dp[n] = ans;
    }

    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};