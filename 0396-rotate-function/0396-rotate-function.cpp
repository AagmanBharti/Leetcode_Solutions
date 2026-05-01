class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long sum = 0;
        long func = 0;

        for(int i = 0;i<n;i++){
            sum += nums[i];
            func += (long)i * nums[i];
        }

        long result = func;

        for(int k = 1;k < n;k++){
            func = func + sum - (long)n * nums[n-k];
            result = max(result,func);
        }
        return (int)result;
    }
};