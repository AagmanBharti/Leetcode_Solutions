class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int total = accumulate(cardPoints.begin(),
                               cardPoints.end(), 0);

        // Cards that we leave behind
        int windowSize = n - k;

        int windowSum = 0;

        // First window of size n-k
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minWindowSum = windowSum;

        // Sliding window
        for (int right = windowSize; right < n; right++) {

            windowSum += cardPoints[right];
            windowSum -= cardPoints[right - windowSize];

            minWindowSum = min(minWindowSum, windowSum);
        }

        return total - minWindowSum;
    }
};