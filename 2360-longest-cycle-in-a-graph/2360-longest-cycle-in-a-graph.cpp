class Solution {
public:
    int maxLength = -1;

    void dfs(int node, vector<int>& edges,
             vector<int>& visited, vector<int>& pathVisited,
             vector<int>& path) {

        if (node == -1 || visited[node]) {
            if (node != -1 && pathVisited[node]) {
                int cycleStart = find(path.begin(), path.end(), node) - path.begin();

                int cycleLength = path.size() - cycleStart;
                maxLength = max(maxLength, cycleLength);
            }
            return;
        }

        visited[node] = 1;
        pathVisited[node] = 1;
        path.push_back(node);

        dfs(edges[node], edges, visited, pathVisited, path);

        pathVisited[node] = 0;
        path.pop_back();
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> path;
                dfs(i, edges, visited, pathVisited, path);
            }
        }

        return maxLength;
    }
};