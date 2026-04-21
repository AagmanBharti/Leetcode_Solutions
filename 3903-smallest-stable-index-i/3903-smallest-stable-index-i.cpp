class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> mini(n);

        mini[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; i--){
            mini[i] = min(mini[i+1], nums[i]);
        }
        
        int pref = nums[0];
        for(int i = 0;i<n;i++){
            pref = max(pref,nums[i]);

            int score = pref - mini[i];
            if(score <= k) return i;
        }
return -1;
        
    }
};