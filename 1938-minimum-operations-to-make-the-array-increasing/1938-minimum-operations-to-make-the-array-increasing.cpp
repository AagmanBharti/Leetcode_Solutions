class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n-1;i++){
            int diff = nums[i] - nums[i+1];
                if(nums[i+1] > nums[i]){
                    continue;
                }
                else {
                    nums[i+1] += diff+1;
                    count += diff+1;
                }
            }
            return count;
    }
};