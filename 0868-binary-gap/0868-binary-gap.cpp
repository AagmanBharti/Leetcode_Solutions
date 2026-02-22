class Solution {
public:
    int binaryGap(int n) {
    while ((n & 1) == 0) n >>= 1;  // remove trailing zeros

    int ans = 0, dist = 0;

    while (n > 0) {
        n >>= 1;
        dist++;

        if (n & 1) {
            ans = max(ans, dist);
            dist = 0;
        }
    }

    return ans;
}
};