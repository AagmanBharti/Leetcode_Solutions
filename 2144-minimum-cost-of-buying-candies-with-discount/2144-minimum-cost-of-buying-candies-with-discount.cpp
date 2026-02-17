class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int minCost = 0;
        int cnt = 0;
        for(int i = cost.size() - 1;i >= 0;i--){
           if(cnt == 2){
            cnt = 0;
            continue;
           } else {
            cnt++;
           }
           minCost += cost[i];
        }
        return minCost;
    }
};