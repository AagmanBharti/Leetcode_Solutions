class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // Step 1: Precompute cost of every substring
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;
                int mini = n;

                // Try every proper divisor
                for (int d = 1; d < len; d++) {
                    if (len % d != 0)
                        continue;

                    int cnt = 0;

                    // Check all groups
                    for (int offset = 0; offset < d; offset++) {

                        int l = i + offset;
                        int r = j - d + 1 + offset;

                        while (l < r) {
                            if (s[l] != s[r])
                                cnt++;

                            l += d;
                            r -= d;
                        }
                    }

                    mini = min(mini, cnt);
                }

                cost[i][j] = mini;
            }
        }

        // Step 2: DP
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                // Previous partition point
                for (int h = 0; h <= i - 2; h++) {

                    dp[i][j] = min(dp[i][j], dp[h][j - 1] + cost[h][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};
