class Solution {
public:

    int f(int idx, int tranNo, vector<int>& prices, int n, int k, vector<vector<int>>& dp){
        if(idx == n || tranNo == 2*k) return 0;
        if(dp[idx][tranNo] != -1) return dp[idx][tranNo];
        if(tranNo % 2 == 0){
            return dp[idx][tranNo] = max(-prices[idx] + f(idx + 1, tranNo + 1, prices, n, k,dp), 0 + f(idx + 1, tranNo, prices, n, k,dp));
        }
        return dp[idx][tranNo] = max(prices[idx] + f(idx + 1, tranNo + 1, prices, n, k,dp), 0 + f(idx + 1, tranNo, prices, n, k,dp));
    }

    int maxProfit(int k, vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2*k,-1));
        return f(0, 0, prices, n, k, dp);
    }
};