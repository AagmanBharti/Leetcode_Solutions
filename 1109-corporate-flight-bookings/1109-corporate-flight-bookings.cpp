class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);

        // Step 1: Apply difference array updates
        for (auto &b : bookings) {
            int first = b[0] - 1;  // convert to 0-based index
            int last = b[1] - 1;
            int seats = b[2];

            diff[first] += seats;
            if (last + 1 < n)
                diff[last + 1] -= seats;
        }

        // Step 2: Prefix sum to get final result
        vector<int> result(n, 0);
        result[0] = diff[0];

        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] + diff[i];
        }

        return result;
    }
};