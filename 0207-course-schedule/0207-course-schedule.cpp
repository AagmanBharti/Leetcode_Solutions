class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // Build graph
        for(auto& it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        // Calculate indegree
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Courses with indegree 0
        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // BFS
        while(!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for(auto it : adj[node]) {
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return count == numCourses;
    }
};