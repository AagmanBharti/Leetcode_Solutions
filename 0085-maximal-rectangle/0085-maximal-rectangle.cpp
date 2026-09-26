class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> st;

        int ans = 0;

        for (int i = 0; i <= n; i++) {

            int currHeight = (i == n ? 0 : heights[i]);

            while (!st.empty() && heights[st.top()] > currHeight) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                ans = max(ans, height * width);
            }

            st.push(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        int ans = 0;

        for (int i = 0; i < rows; i++) {

            // Build histogram
            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            // Largest rectangle for this row
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};