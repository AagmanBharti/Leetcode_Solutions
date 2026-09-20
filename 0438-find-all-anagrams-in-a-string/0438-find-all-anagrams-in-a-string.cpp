class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n)
            return ans;

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        for (char c : p) {
            pFreq[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < n; right++) {

            windowFreq[s[right] - 'a']++;

            if (right - left + 1 > m) {
                windowFreq[s[left] - 'a']--;
                left++;
            }

            if (right - left + 1 == m && windowFreq == pFreq) {

                ans.push_back(left);
            }
        }

        return ans;
    }
};