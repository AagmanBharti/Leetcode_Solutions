
class Solution {
public:
    using ll = long long;

    static const ll MOD1 = 1000000007;
    static const ll MOD2 = 1000000009;
    static const ll BASE = 131;

    vector<ll> h1, h2;
    vector<ll> p1, p2;

    // Returns combined hash of subarray [l, r]
    ll getHash(int l, int r) {
        int len = r - l + 1;

        ll hash1 = (h1[r + 1] -
                     h1[l] * p1[len] % MOD1 + MOD1) % MOD1;

        ll hash2 = (h2[r + 1] -
                     h2[l] * p2[len] % MOD2 + MOD2) % MOD2;

        return hash1 * MOD2 + hash2;
    }

    // Checks whether a unique subarray of length len exists
    bool check(int len, int n) {
        unordered_map<ll, int> freq;

        for (int i = 0; i + len <= n; i++) {
            ll hash = getHash(i, i + len - 1);
            freq[hash]++;
        }

        for (auto &it : freq) {
            if (it.second == 1) {
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);

        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);

        // Prefix hash and powers
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i]) % MOD2;

            p1[i + 1] = p1[i] * BASE % MOD1;
            p2[i + 1] = p2[i] * BASE % MOD2;
        }

        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
