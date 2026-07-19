class Solution {
public:
    int fibo(int idx, vector<int>& dp) {
        if (idx == 0 || idx == 1)
            return idx;

        if (dp[idx] != -1)
            return dp[idx];

        return dp[idx] = fibo(idx - 1, dp) + fibo(idx - 2, dp);
    }

    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return fibo(n, dp);
    }
};