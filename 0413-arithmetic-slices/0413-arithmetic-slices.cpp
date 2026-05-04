class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int n = nums.size();
        int i = 0, k = 2;
        int diff = nums[1] - nums[0];
        int cnt = 0;

        while(k < n){
            if(nums[k] - nums[k-1] == diff){
                cnt += (k - i - 1);
                k++;
            } else {
                diff = nums[k] - nums[k-1];
                i = k - 1;
                k++;
            }
        }
        return cnt;   
    }
};