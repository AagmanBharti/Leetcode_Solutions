class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {

        // Process current cell
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Invalid prefix
        if (balance < 0)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1) {
            return balance == 0;
        }

        // Memoization
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool ans = false;

        // Down
        if (i + 1 < m) {
            ans = ans || solve(grid, i + 1, j, balance);
        }

        // Right
        if (j + 1 < n) {
            ans = ans || solve(grid, i, j + 1, balance);
        }

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0)
            return false;

        dp.assign(m, vector<vector<int>>(n, vector<int>(m + n + 1, -1)));

        return solve(grid, 0, 0, 0);
    }
};