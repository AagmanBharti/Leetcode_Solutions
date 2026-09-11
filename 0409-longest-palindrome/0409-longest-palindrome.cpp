class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mpp;
        int oddCount = 0;

        for(char c : s){
            mpp[c]++;
            if(mpp[c] % 2 == 1) oddCount++;
            else oddCount--;
        }

        if(oddCount > 1){
            return s.size() - oddCount + 1;
        }
        return s.size();
    }
};