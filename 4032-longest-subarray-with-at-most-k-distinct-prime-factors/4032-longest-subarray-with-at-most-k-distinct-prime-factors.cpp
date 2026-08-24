class Solution {
public:
    vector<int> getPrimeFactors(int n) {
        vector<int> factors;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);

                while (n % i == 0)
                    n /= i;
            }
        }

        if (n > 1)
            factors.push_back(n);

        return factors;
    }

    int longestSubarray(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;

        // frequency of each prime in current window
        unordered_map<int, int> freq;

        // Store prime factors of every number
        vector<vector<int>> factors(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            factors[i] = getPrimeFactors(nums[i]);
        }

        int distinct = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add nums[right]
            for (int p : factors[right]) {
                if (freq[p] == 0)
                    distinct++;

                freq[p]++;
            }

            // Shrink window if more than k distinct primes
            while (distinct > k) {

                for (int p : factors[left]) {
                    freq[p]--;

                    if (freq[p] == 0)
                        distinct--;
                }

                left++;
            }

            // Current window is valid
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};