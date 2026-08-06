class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjLs){
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it, vis, adjLs);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(n);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<int> vis(n,0);
        for(int i = 0;i < n;i++){
            if(!vis[i]){
                count++;
                dfs(i, vis, adjLs);
            }
        }
        return count;
    }
};