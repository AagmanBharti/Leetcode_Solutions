class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> adjLs(n);

        for(auto& it : edges) {
            adjLs[it[0]].push_back(it[1]);
            adjLs[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(source);
        vis[source] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination) return true;

            for(auto& adj: adjLs[node]){
                if(!vis[adj]){
                    vis[adj] = true;
                    q.push(adj);
            }
        }
        }
        return false;
    }
};