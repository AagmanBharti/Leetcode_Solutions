class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);
        for (auto& it : prerequisites) {
            courses[it[0]].push_back(it[1]);
        }

        vector<int> indegree(numCourses);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : courses[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : courses[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return count == numCourses;
    }
};