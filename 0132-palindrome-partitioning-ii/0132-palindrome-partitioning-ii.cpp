class Solution {
public:
    bool isPalindrome(int i, int j, string& s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int func(int i, int n, string& s, vector<int>& dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int minCost = INT_MAX;

        for(int j = i; j < n;j++){
            if(isPalindrome(i, j, s)){
            int cost = 1 + func(j + 1, n, s, dp);
            minCost = min(minCost, cost);
        }
        }
        return dp[i] = minCost;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return func(0, n, s, dp) - 1;
    }
};