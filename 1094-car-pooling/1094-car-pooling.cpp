class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> timeline(1001, 0); // constraint: location <= 1000

    for (auto &trip : trips) {
        int num = trip[0];
        int from = trip[1];
        int to = trip[2];

        timeline[from] += num;   // pick up
        timeline[to] -= num;     // drop off
    }

    int curr = 0;
    for (int i = 0; i <= 1000; i++) {
        curr += timeline[i];
        if (curr > capacity) return false;
    }

    return true;
    }
};