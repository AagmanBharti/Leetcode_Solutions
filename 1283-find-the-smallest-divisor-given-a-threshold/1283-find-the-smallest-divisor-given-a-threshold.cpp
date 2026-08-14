class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int threshold) {
        int sum = 0;

        for (int num : nums) {
            sum += ceil((double)num / k);
        }

        return sum <= threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, mid, threshold)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};