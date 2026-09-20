class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> hash(26, 0);

        for (char c : s1) {
            hash[c - 'a']++;
        }

        vector<int> need(26, 0);

        int left = 0;

        for (int right = 0; right < m; right++) {

            need[s2[right] - 'a']++;

            if (right - left + 1 > n) {
                need[s2[left] - 'a']--;
                left++;
            }

            if (right - left + 1 == n && need == hash) {
                return true;
            }
        }

        return false;
    }
};