class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0;
        int maxArea = 0;
        for(int i=0;i<dimensions.size();i++){
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int diag = l*l + w*w;

            if(diag > maxDiag || (diag == maxDiag && l*w>maxArea)){
                maxDiag = diag;
                maxArea = l*w;
            }
        }
        return maxArea;
    }
};