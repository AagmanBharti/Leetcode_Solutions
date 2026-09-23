class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }

        int target = totalSum - x;
        if(target < 0) return -1;
        if(target == 0) return nums.size();

        int sum = 0;
        int left = 0;
        int len = -1;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(left <= right && sum > target){
                sum -= nums[left];
                left++;
            }

            if(sum == target){
                len = max(len, right - left + 1);
            }
        }

        return len == -1 ? -1 : nums.size()-len;
    }
};