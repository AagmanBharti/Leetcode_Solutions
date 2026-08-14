class Solution {
public:
bool possible(vector<int>& bloomDay, int day, int m, int k) {

    int bouquets = 0;
    int consecutive = 0;

    for(int flower : bloomDay) {

        if(flower <= day) {
            consecutive++;

            if(consecutive == k) {
                bouquets++;
                consecutive = 0;
            }
        }
        else {
            consecutive = 0;
        }
    }

    return bouquets >= m;
}

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long required = 1LL * m * k;

        if(required > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};