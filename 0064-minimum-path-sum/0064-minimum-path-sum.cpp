class Solution {
public:
    int addition(int i, int j, int m, int n,
                 vector<vector<int>>& dp,
                 vector<vector<int>>& grid) {

        if (i > m || j > n)
            return 1e9;

        if (i == m && j == n)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = addition(i, j + 1, m, n, dp, grid);
        int down  = addition(i + 1, j, m, n, dp, grid);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return addition(0, 0, m - 1, n - 1, dp, grid);
    }
};