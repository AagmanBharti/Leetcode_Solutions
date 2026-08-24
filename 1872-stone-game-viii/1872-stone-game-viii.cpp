class Solution {
public:
    int n;
    vector<long long> s;
    vector<long long> dp;

    long long maxDiff(int i) {
        if (i == n - 1)
            return s[n - 1];

        if (dp[i] != LLONG_MIN)
            return dp[i];

        return dp[i] = max(maxDiff(i + 1),
                           s[i] - maxDiff(i + 1));
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();

        s.resize(n);
        dp.assign(n, LLONG_MIN);

        s[0] = stones[0];
        for (int i = 1; i < n; i++) {
            s[i] = s[i - 1] + stones[i];
        }

        return maxDiff(1);
    }
};