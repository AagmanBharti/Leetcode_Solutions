class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // Step - 1: Sort dimensions of each cuboids
        for(auto &c : cuboids){
            sort(c.begin(), c.end());
        }

        // Step 2: Sort all cuboids
        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();

        vector<int> dp(n);

        int ans = 0;

        for (int i = 0; i < n; i++) {

            dp[i] = cuboids[i][2];   // height of current cuboid

            for (int prev = 0; prev < i; prev++) {

                if (cuboids[prev][0] <= cuboids[i][0] &&
                    cuboids[prev][1] <= cuboids[i][1] &&
                    cuboids[prev][2] <= cuboids[i][2]) {

                    dp[i] = max(dp[i],
                                dp[prev] + cuboids[i][2]);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};