class Solution {
public:
    const int dir[5] = {0,1,0,-1,0};
    int m,n;
    unordered_map<int, int> componentSize;

    void paint(vector<vector<int>>& grid, int r, int c, int color){
        if(r < 0 || r == m || c < 0 || c == n || grid[r][c] != 1) return;
        grid[r][c] = color;
        componentSize[color] += 1;
        for(int i = 0;i < 4;i++) paint(grid, r + dir[i], c + dir[i+1], color);
    }

    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        int nextcolor = 2;

        for(int r = 0;r < m;r++){
            for(int c = 0;c < n;c++){
                if(grid[r][c] != 1) continue;
                paint(grid, r, c, nextcolor++);
                ans = max(ans, componentSize[nextcolor - 1]);
            }
        }

        for(int r = 0;r < m;r++){
            for(int c = 0;c < n;c++){
                if(grid[r][c] != 0) continue;
                unordered_set<int> neighborcolors;
                for(int i = 0;i < 4;i++){
                    int nr = r + dir[i];
                    int nc = c + dir[i+1];

                    if(nr < 0 || nr == m || nc < 0 || nc == n || grid[nr][nc] == 0) continue;
                    neighborcolors.insert(grid[nr][nc]);
                }
                int sizeFormed = 1;
                for(int color : neighborcolors) sizeFormed += componentSize[color];
                ans = max(ans, sizeFormed);
            }
        }
        return ans;
    }
};