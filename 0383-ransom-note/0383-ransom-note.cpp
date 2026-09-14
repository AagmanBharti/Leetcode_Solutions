class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mpp1, mpp2;

        for(char c : ransomNote) mpp1[c]++;
        for(char c : magazine) mpp2[c]++;

        for(char c : ransomNote){
            if(mpp2[c] < mpp1[c]) return false;
        }
        return true;
    }
};