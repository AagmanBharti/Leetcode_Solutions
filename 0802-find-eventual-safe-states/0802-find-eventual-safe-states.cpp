class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        // Reverse graph
        vector<vector<int>> adjRev(n);

        // indegree[i] = number of outgoing edges
        // from i in the original graph
        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++) {

            for(auto it : graph[i]) {

                // Original:
                // i -> it

                // Reverse:
                // it -> i
                adjRev[it].push_back(i);

                indegree[i]++;
            }
        }

        queue<int> q;

        // Terminal nodes are initially safe
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            // Go to nodes that point to 'node'
            for(auto it : adjRev[node]) {

                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Problem requires sorted order
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};