
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        long long total = 0;
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            maxDiff = max(maxDiff, diff[i]);
        }

        if (k >= total) return 0;

        int low = 0, high = maxDiff;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                needed += max(0, d - mid);
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;
        long long used = 0;
        long long ans = 0;

        for (int d : diff) {
            used += max(0, d - level);
            int finalDiff = min(d, level);
            ans += 1LL * finalDiff * finalDiff;
        }

        long long remaining = k - used;

        for (int d : diff) {
            if (remaining == 0) break;

            if (d >= level) {
                ans -= 1LL * level * level;
                ans += 1LL * (level - 1) * (level - 1);
                remaining--;
            }
        }

        return ans;
    }
};
