class Solution {
public:
    bool isPossible(vector<int>& weights, int k, int days) {
        int day = 1;
        int current = 0;

        for (int weight : weights) {

            if (current + weight > k) {
                day++;
                current = 0;
            }

            current += weight;
        }

        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(weights, mid, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};