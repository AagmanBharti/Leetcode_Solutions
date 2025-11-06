class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses,vector<int>());
        vector<int> indegree(numCourses);
        for(vector<int>&ans : prerequisites){
            adj[ans[1]].push_back(ans[0]);
            indegree[ans[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        int vis=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            vis++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(vis == numCourses) return topo;
        return {};

    }
};