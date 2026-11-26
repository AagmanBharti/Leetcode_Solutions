class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        long long cost = 0;
        long long ans = 0;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            // Step 1: Add nums[i] to the window
            while (!dq.empty() && nums[dq.back()] < nums[i]) {

                int l = dq.back();
                dq.pop_back();

                int r = dq.empty() ? j + 1 : dq.back();

                // Increase this segment to nums[i]
                cost += 1LL * (r - l) * (nums[i] - nums[l]);
            }

            dq.push_back(i);

            // Step 2: Shrink window if cost exceeds k
            while (cost > k) {

                cost -= nums[dq.front()] - nums[j];

                if (dq.front() == j) {
                    dq.pop_front();
                }

                j--;
            }

            // Step 3: Count valid subarrays ending at j
            ans += j - i + 1;
        }

        return ans;
    }
};
