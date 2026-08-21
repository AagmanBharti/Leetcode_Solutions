class Solution {
public:

    long long countValid(long long x, vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        // All non-empty subsets
        for (int mask = 1; mask < (1 << n); mask++) {

            long long lcm = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    bits++;

                    long long g = std::gcd(lcm, (long long)coins[i]);

                    lcm = (lcm / g) * coins[i];

                    if (lcm > x) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow)
                continue;

            long long ways = x / lcm;

            if (bits % 2 == 1)
                count += ways;
            else
                count -= ways;
        }

        return count;
    }


    long long findKthSmallest(vector<int>& coins, int k) {

        long long minCoin =
            *min_element(coins.begin(), coins.end());

        long long low = 1;
        long long high = minCoin * 1LL * k;

        while (low < high) {

            long long mid =
                low + (high - low) / 2;

            if (countValid(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};