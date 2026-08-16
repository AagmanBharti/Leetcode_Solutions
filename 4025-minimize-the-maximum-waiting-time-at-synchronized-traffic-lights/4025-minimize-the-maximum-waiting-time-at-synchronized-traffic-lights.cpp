class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxGreen = *max_element(lights.begin(), lights.end());

        int ans = 0;

        for (int t : arrivalTime) {
            int r = t % period;

            if (r >= maxGreen) {
                int wait = period - r;
                ans = max(ans, wait);
            }
        }

        return ans;
    }
};