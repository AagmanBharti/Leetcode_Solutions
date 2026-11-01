class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> mark(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    mark[i][j] = 1;
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int total_time = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            total_time = max(total_time, time);

            for(int i = 0;i < 4;i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >= 0 && newc >= 0 && newr < m && newc < n && grid[newr][newc] == 1 && mark[newr][newc] == 0){
                    mark[newr][newc] = 1;
                    q.push({{newr, newc}, time + 1});
                }
            }
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1 && mark[i][j] == 0){
                    return -1;
                }
            }
        }

        return total_time;
    }
};