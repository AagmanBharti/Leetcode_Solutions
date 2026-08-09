class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        int dr[] = {1,0,-1,0};
        int dc[] = {0,-1,0,1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(effort > dist[row][col]) continue;

            for(int k = 0;k < 4;k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                    int edge = abs(heights[row][col] - heights[nrow][ncol]);
                    int newEffort = max(effort, edge);

                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};