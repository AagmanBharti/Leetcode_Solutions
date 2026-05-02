class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0;
    int n = nums.size();
    int sum = 0;
    int len = INT_MAX;

    while (right < n) {
        sum += nums[right];
        right++;

        while (sum >= target) {
            len = min(len, right - left);
            sum -= nums[left];
            left++;
        }
    }

    return (len == INT_MAX) ? 0 : len;
    }
};