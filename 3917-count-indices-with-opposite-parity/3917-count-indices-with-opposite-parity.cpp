class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n,0);

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i] % 2 == 0){
                    if(nums[j] % 2 != 0) count[i]++;
                }
                else{
                    if(nums[j] % 2 == 0) count[i]++;
                }
            }
        }
        return count;
    }
};