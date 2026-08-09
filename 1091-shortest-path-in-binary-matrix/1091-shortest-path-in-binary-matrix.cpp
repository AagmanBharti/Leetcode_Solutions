class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1) return -1;
        if(grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> vis(n, vector<int>(n,0));
        queue<pair<int, pair<int, int>>> q;

        vis[0][0] = 1;
        q.push({1,{0,0}});

        int delrow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delcol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if(row == n-1 && col == n-1) return dis;

            for(int i = 0;i < 8;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({dis+1, {nrow,ncol}});
                }
            }
        }
        return -1;
    }
};