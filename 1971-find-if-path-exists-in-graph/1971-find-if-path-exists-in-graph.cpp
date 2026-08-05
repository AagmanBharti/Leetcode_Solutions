class Solution {
public:
    bool dfs(int node, int dest, vector<vector<int>>& adjLs, vector<bool>& vis) {

        if(node == dest) return true;
        vis[node] = true;

        for(int adj : adjLs[node]) {
            if(!vis[adj]) {
                if(dfs(adj, dest, adjLs, vis))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> adjLs(n);

        for(auto& it : edges) {
            adjLs[it[0]].push_back(it[1]);
            adjLs[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);

        return dfs(source, destination, adjLs, vis);
    }
};