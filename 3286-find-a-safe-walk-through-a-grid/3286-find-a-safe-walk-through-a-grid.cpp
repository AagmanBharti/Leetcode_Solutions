class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> maxHealth(n, vector<int>(m,-1));
        queue<pair<int, pair<int, int>>> q;

        int initial = health - grid[0][0];
        if(initial <= 0) return false;

        q.push({initial, {0,0}});
        maxHealth[0][0] = initial;

        while(!q.empty()){
            auto [currHealth, pos] = q.front();
            q.pop();

            int row = pos.first;
            int col = pos.second;

            if(row == n-1 && col == m-1) return true;

            for(int d = 0;d < 4;d++){
                int newR = row + dx[d];
                int newC = col + dy[d];

                if(newR < 0 || newC < 0 || newR >= n || newC >= m) continue;

                int remainingHealth = currHealth - grid[newR][newC];

                if(remainingHealth <= 0) continue;
                if(remainingHealth <= maxHealth[newR][newC]) continue;

                maxHealth[newR][newC] = remainingHealth;
                q.push({remainingHealth, {newR,newC}});
            }
        }
        return false;
    }
};