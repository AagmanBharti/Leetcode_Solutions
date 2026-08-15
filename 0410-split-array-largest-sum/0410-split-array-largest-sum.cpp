class Solution {
public:
    int count(vector<int>& nums, int maxSum) {
        int subarrays = 1;
        long long subarraySum = 0;

        for (int num : nums) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                subarrays++;
                subarraySum = num;
            }
        }

        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int subarrays = count(nums, mid);

            if (subarrays > k) {
                // maxSum is too small
                low = mid + 1;
            } else {
                // maxSum is possible
                high = mid - 1;
            }
        }

        return low;
    }
};