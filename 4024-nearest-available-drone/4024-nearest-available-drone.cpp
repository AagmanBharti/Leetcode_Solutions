class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int idx = -1;
        int minD = INT_MAX;

        for(int i = 0;i < drones.size(); i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];

            int dist = abs(x - target[0]) + abs(y - target[1]);
            if(dist <= range && dist < minD){
                minD = dist;
                idx = i;
            }
        }
        return idx;
    }
};