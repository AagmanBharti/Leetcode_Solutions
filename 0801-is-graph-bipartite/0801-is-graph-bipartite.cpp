class Solution {
private:
    bool dfs(int node,vector<vector<int>>& graph,vector<int> &color,int currentColor){
        color[node] = currentColor;
        for(int it: graph[node]){
            if(color[it] == 0){
                if(!dfs(it,graph,color,currentColor * -1)){
                    return false;
                }
            }
                else if(color[it] == currentColor){
                    return false;
                }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        for(int i=0;i<n;i++){
            if(color[i] == 0){
                if(!dfs(i,graph,color,-1)) return false;
            }
        }
        return true;
    }
};