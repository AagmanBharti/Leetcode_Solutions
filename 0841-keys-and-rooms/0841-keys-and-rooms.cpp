class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();

        vector<int> visited(n, 0);
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        int count = 1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int key : rooms[node]) {

                if (!visited[key]) {

                    visited[key] = 1;
                    count++;
                    q.push(key);
                }
            }
        }

        return count == n;
    }
};