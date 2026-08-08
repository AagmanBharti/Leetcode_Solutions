class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = first unmatched index of word2
        // when matching word2 from the end using word1[i...n-1]
        vector<int> suf(n + 1, m);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }

            suf[i] = j + 1;
        }

        vector<int> ans;

        j = 0;
        bool usedMismatch = false;

        for (int i = 0; i < n && j < m; i++) {

            // Case 1: Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Case 2: Use our one allowed mismatch
            else if (!usedMismatch) {

                // After choosing i, can the rest match exactly?
                int matchedSuffix = m - suf[i + 1];
                int needed = m - (j + 1);

                if (matchedSuffix >= needed) {
                    ans.push_back(i);
                    j++;
                    usedMismatch = true;
                }
            }
        }

        if (ans.size() != m)
            return {};

        return ans;
    }
};