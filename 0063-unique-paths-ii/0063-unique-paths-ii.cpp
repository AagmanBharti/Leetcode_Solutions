class Solution {
public:
    int ways(int i,int j,int m,int n,vector<vector<int>>& dp,
         vector<vector<int>>& obstacleGrid){

    if(i > m || j > n)
        return 0;

    if(obstacleGrid[i][j] == 1)
        return 0;

    if(i == m && j == n)
        return 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    int right = ways(i,j+1,m,n,dp,obstacleGrid);
    int down  = ways(i+1,j,m,n,dp,obstacleGrid);

    return dp[i][j] = right + down;
}

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return ways(0,0,m-1,n-1,dp,obstacleGrid);
    }
};