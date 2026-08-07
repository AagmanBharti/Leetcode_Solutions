class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<pair<int,int>, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            dist[row][col] = dis;

            for(int i = 0; i < 4; i++) {

                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >= 0 && newr < m &&
                   newc >= 0 && newc < n &&
                   !vis[newr][newc]) {

                    vis[newr][newc] = 1;
                    q.push({{newr, newc}, dis + 1});
                }
            }
        }

        return dist;
    }
};