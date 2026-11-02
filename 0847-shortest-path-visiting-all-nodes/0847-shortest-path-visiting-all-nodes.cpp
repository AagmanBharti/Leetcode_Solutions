class Solution {
public:
    typedef pair<int, int> P;

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        if (n == 1 || n == 0)
            return 0;

        queue<P> q;     //{node, mask}
        set<P> visited; //{node, pathMask}

        for (int i = 0; i < n; i++) {
            int maskValue = (1 << i);
            q.push({i, maskValue});
            visited.insert({i, maskValue});
        }

        int allVisited = (1 << n) - 1; // 2 powered to n

        int path = 0;

        while (!q.empty()) {
            int size = q.size();
            path++;

            while (size--) {
                auto curr = q.front();
                q.pop();

                int currNode = curr.first;
                int currMask = curr.second;

                for (auto it : graph[currNode]) {
                    int nextMask = currMask | (1 << it);

                    if (nextMask == allVisited)
                        return path;
                    if (visited.find({it, nextMask}) == visited.end()) {
                        visited.insert({it, nextMask});
                        q.push({it, nextMask});
                    }
                }
            }
        }
        return -1;
    }
};