class Solution {
public:
    bool possible(vector<int>& position, int m, int k) {
        int countBalls = 1;
        int lastPlaced = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPlaced >= k) {
                countBalls++;
                lastPlaced = position[i];
            }
            if (countBalls >= m)
                return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = (position[position.size() - 1] - position[0]) / (m - 1);

        int ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(position, m, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};