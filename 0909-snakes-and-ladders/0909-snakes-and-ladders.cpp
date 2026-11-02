class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        queue<int> q;
        vector<int> vis(n * n + 1, 0);

        q.push(1);
        vis[1] = 1;

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int curr = q.front();
                q.pop();

                if (curr == n * n)
                    return moves;

                // Try all dice values
                for (int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;

                    if (next > n * n)
                        break;

                    // Convert 1D to 2D
                    int r = (next - 1) / n;
                    int c = (next - 1) % n;

                    int row = n - 1 - r;

                    if (r % 2 == 1)
                        c = n - 1 - c;

                    // Check snake or ladder
                    if (board[row][c] != -1) {
                        next = board[row][c];
                    }

                    // BFS visited check
                    if (!vis[next]) {
                        vis[next] = 1;
                        q.push(next);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};