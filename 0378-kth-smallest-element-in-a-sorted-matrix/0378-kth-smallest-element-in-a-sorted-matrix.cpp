class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        for(int row = 0; row < n; row++){
            pq.push({matrix[row][0], row, 0});
        }

        for (int i = 0; i < k - 1; i++) {

            auto [value, row, col] = pq.top();
            pq.pop();

            // Put next element from the same row
            if (col + 1 < n) {
                pq.push({
                    matrix[row][col + 1],
                    row,
                    col + 1
                });
            }
        }

        return get<0>(pq.top());
    }
};