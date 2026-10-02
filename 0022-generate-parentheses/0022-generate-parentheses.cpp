class Solution {
    vector<string> ans;
    string curr;
public:
    void dfs(int open, int close){
        if(open == 0 && close == 0){
            ans.push_back(curr);
            return;
        }
        if(open > 0){
            curr.push_back('(');
            dfs(open - 1, close);
            curr.pop_back();
        }
        if(close > open){
            curr.push_back(')');
            dfs(open, close - 1);
            curr.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return ans;
    }
};