class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        for(int i = 0;i<m;i++){
            int rowOnes = 0;
            int colIdx = -1;
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    rowOnes++;
                    colIdx = j;
                }
            }

            if(rowOnes == 1){
                int colOnes = 0;
                for(int k = 0;k<m;k++){
                    if(mat[k][colIdx] == 1){
                        colOnes++;
                    }
                }
                if(colOnes == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};