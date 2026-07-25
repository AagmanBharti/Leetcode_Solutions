class Solution {
public:

    int func(int i, int j, vector<int>& values, vector<vector<int>>& dp){
        if(dp[i][j] != 0) return dp[i][j];
        int res = 0;
        for(int k = i + 1; k < j;k++){
            res  = min(res == 0 ? INT_MAX : res, func(i, k, values, dp) + values[i] * values[k] * values[j] + func(k, j, values, dp));
        }
        return dp[i][j] = res;
    }

    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(50, vector<int>(50, 0));
        int n = values.size();
        return func(0, n-1, values, dp); 
    }
};