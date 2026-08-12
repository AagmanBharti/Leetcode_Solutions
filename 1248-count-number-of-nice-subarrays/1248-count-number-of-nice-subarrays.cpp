class Solution {
public:

    int count(vector<int>& nums, int k){
        int cnt = 0;
        int sum = 0;
        int n = nums.size();
        int left = 0;

        for(int right = 0;right < n;right++){
            sum += nums[right]%2;

            while(sum > k){
                sum -= nums[left]%2;
                left++;
            }

            cnt += right - left + 1;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums, k) - count(nums, k-1); 
    }
};