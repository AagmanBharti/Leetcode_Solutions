class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int m = grid.size(), n = grid[0].size();

        for(int i = 0;i < 4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));

        int count = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};