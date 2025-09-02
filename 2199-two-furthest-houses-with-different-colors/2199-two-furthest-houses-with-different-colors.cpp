class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans1 = INT_MIN;
        int ans2 = INT_MIN;
        int n = colors.size();

        int k = 1;
        while(k < n){
            if(colors[0] != colors[k]) ans1 = max(ans1,k);
            if(colors[k] != colors[n-1]) ans2 = max(ans2,n-1-k);
            k++;
        }
        return max(ans1,ans2);
    }
};