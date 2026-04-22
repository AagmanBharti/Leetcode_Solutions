class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n,vector<int>(m,0));
        sort(sources.begin(),sources.end(),[](auto &a,auto &b){
            return a[2] > b[2];
        });

        queue<pair<int,int>> q;
        for(auto it: sources){
            int r = it[0];
            int c = it[1];
            int color = it[2];

            q.push({r,c});
            grid[r][c] = color;
        }

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        while(!q.empty()){
            int size = q.size();
            int r = q.front().first;
            int c = q.front().second;
            int colour = grid[r][c];
            q.pop();

                for(int i=0;i<4;i++){
                    int nrow = r+dx[i];
                    int ncol = c+dy[i];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol]== 0){
                        q.push({nrow,ncol});
                        grid[nrow][ncol]=colour;
                    }
            }
        }
    return grid;

    }
};