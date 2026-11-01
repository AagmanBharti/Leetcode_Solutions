class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1) return -1;
        if(grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        q.push({{0,0}, 1});

        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            if(row == n-1 && col == n-1) return dist;

            for(int i = 0;i < 8;i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >= 0 && newc >= 0 && newr < n && newc < n && !vis[newr][newc] && grid[newr][newc] == 0){
                    vis[newr][newc] = 1;
                    q.push({{newr, newc}, dist + 1});
                }
            }
        }
        return -1;
    }
};