class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();

        queue<pair<int, vector<bool>>> q;

        set<pair<int, vector<bool>>> visited;

        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            vis[i] = true;

            q.push({i, vis});
            visited.insert({i, vis});
        }

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [node, vis] = q.front();
                q.pop();

                bool allVisited = true;

                for (bool x : vis) {
                    if (!x) {
                        allVisited = false;
                        break;
                    }
                }

                if (allVisited)
                    return steps;

                for (int neighbor : graph[node]) {

                    vector<bool> newVis = vis;
                    newVis[neighbor] = true;

                    if (!visited.count({neighbor, newVis})) {

                        visited.insert({neighbor, newVis});
                        q.push({neighbor, newVis});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};