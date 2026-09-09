class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            // Current element cannot be part of any valid subarray
            if (nums[right] > threshold) {
                left = right + 1;
                continue;
            }

            // If current element is odd, it cannot be a starting point.
            // If left == right, we are trying to start here.
            if (left == right && nums[right] % 2 != 0) {
                left++;
                continue;
            }

            // Alternation is broken
            if (right > left &&
                nums[right] % 2 == nums[right - 1] % 2) {
                
                // Current element can only become a new start if even
                if (nums[right] % 2 == 0)
                    left = right;
                else
                    left = right + 1;
            }

            if (left <= right)
                ans = max(ans, right - left + 1);
        }

        return ans;
    }
};