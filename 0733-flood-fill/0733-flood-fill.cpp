class Solution {
public:
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};

    void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int color,int iniColor){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();

        for(int i = 0;i<4;i++){
            int nRow = row + delrow[i];
            int nCol = col + delcol[i];

            if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && image[nRow][nCol] == iniColor && ans[nRow][nCol] != color){
                dfs(nRow,nCol,ans,image,color,iniColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];

        dfs(sr,sc,ans,image,color,iniColor);
        return ans;
        
    }
};