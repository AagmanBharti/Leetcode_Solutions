class Solution {
public:
    int sum(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        int left = 0;

        for(int right = 0; right < n; right++){
            sum += nums[right];

            while(sum > goal){
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sum(nums, goal) - sum(nums, goal - 1);
    }
};