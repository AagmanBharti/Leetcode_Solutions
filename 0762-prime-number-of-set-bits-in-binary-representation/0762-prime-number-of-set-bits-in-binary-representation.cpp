class Solution {
public:
    bool hasPrimeSetBits(int n) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int setBits = 0;
        for (int i = 0; i < 20; i++) {
            if (n & (1 << i)) {
                setBits++;
            }
        }
        if (primes.find(setBits) != primes.end()) {
            return true;
        }
        return false;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (hasPrimeSetBits(i)) {
                ans++;
            }
        }
        return ans;
    }
};