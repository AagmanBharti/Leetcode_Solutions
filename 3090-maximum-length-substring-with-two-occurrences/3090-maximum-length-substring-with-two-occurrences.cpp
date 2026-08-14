class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int left = 0;
        unordered_map<char, int> mpp;

        for(int right = 0; right < s.size(); right++){
            mpp[s[right]]++;

            while(mpp[s[right]] > 2){
                mpp[s[left]]--;
                left++;

                if(mpp[s[left]] == 0) mpp.erase(s[left]);
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};