class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size()-1;
        int n = matrix[0].size();
        
        while (top <= bottom){
            int mid = (top + bottom)/2;
            if(matrix[mid][0] < target && matrix[mid][matrix[mid].size()-1] > target) break;
            else if(matrix[mid][0] > target) bottom = mid-1;
            else top = mid+1;  
        }

        int row = (top + bottom)/2;
        int left = 0,right = matrix[row].size()-1;

        while(left <= right){
            int mid = (left + right)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) right = mid-1;
            else left = mid+1;
    }
    return false;
    }
};