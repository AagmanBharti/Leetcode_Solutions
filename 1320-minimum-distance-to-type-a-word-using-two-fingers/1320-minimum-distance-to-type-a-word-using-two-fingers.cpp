class Solution {
public:
    int dist(int a, int b){
        if(a==26 || b==26) return 0;
        return abs(a/6-b/6) + abs(a%6-b%6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        const int INF = 1e9;

        vector dp(n+1,
                  vector(27, vector<int>(27, INF)));

        dp[0][26][26] = 0;

        for(int i=0;i<n;i++){
            int cur = word[i]-'A';

            for(int f1=0;f1<=26;f1++){
                for(int f2=0;f2<=26;f2++){
                    int val = dp[i][f1][f2];
                    if(val==INF) continue;

                    // move finger1
                    dp[i+1][cur][f2] =
                    min(dp[i+1][cur][f2],
                        val + dist(f1,cur));

                    // move finger2
                    dp[i+1][f1][cur] =
                    min(dp[i+1][f1][cur],
                        val + dist(f2,cur));
                }
            }
        }

        int ans = INF;
        for(int i=0;i<=26;i++)
            for(int j=0;j<=26;j++)
                ans = min(ans, dp[n][i][j]);

        return ans;
    }
};