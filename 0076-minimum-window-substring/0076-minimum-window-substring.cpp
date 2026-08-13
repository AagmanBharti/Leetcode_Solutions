class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size())
            return "";

        unordered_map<char, int> need;
        unordered_map<char, int> have;

        for (char ch : t) {
            need[ch]++;
        }

        int required = need.size();
        int formed = 0;

        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char ch = s[right];

            have[ch]++;

            // This character's requirement is now satisfied
            if (need.count(ch) &&
                have[ch] == need[ch]) {

                formed++;
            }

            // Window is valid
            while (formed == required) {

                // Update answer
                if (right - left + 1 < minLen) {

                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];

                have[leftChar]--;

                // We have fallen below the required frequency
                if (need.count(leftChar) &&
                    have[leftChar] < need[leftChar]) {

                    formed--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};