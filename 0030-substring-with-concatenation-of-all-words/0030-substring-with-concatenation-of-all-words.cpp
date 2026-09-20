class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (totalLen > s.size())
            return ans;

        unordered_map<string, int> target;

        // Required frequency of each word
        for (string word : words) {
            target[word]++;
        }

        // Try every possible offset
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int right = offset;

            unordered_map<string, int> window;

            int count = 0;

            while (right + wordLen <= s.size()) {

                // Get next word
                string word = s.substr(right, wordLen);
                right += wordLen;

                // Word doesn't exist in target
                if (target.find(word) == target.end()) {

                    window.clear();
                    count = 0;
                    left = right;

                    continue;
                }

                // Add word to current window
                window[word]++;
                count++;

                // Too many copies of this word
                while (window[word] > target[word]) {

                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // We have exactly all required words
                if (count == wordCount) {

                    ans.push_back(left);

                    // Move left to look for another answer
                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};