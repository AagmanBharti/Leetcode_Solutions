class Solution {
public:

    int solve(int i,int j,vector<int>& nums,vector<int>& dp){

    if(i==j)
        return dp[i] = nums[i];

    int left = nums[i] - solve(i+1,j,nums,dp);

    int right = nums[j] - solve(i,j-1,nums,dp);

    return dp[i] = max(left,right);
    }

    bool predictTheWinner(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n+1,0);
      return solve(0,n-1,nums,dp)>=0;  
    }
};