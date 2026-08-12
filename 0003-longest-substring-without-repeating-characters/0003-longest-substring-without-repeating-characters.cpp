class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> freq;

        int left = 0;
        int len = 0;

        for(int right = 0; right < s.size(); right++){
            freq[s[right]]++;
            while(freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
            }

            len = max(len, right - left + 1);
        }
        return len;
    }
};