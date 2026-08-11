class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];

        for(int i = 1;i < n;i++){
            if(nums[i] == nums[i-1] + 1) sum += nums[i];
            else break;
        }

        vector<bool> hash(1276, false);
        for(int num : nums){
            hash[num] = true;
        }

        while(hash[sum]) sum++;
        return sum;
    }
};