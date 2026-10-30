class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> ans = image;
        ans[sr][sc] = color;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        queue<pair<int, int>> q;
        q.push({sr,sc});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            for(int i = 0;i < 4;i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == iniColor && ans[nr][nc] != color){
                    ans[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};