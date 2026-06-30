class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] = {-1,-1,-1};
        int count = 0;
        for(int i=0;i<s.size();i++){
            lastSeen[s[i] - 'a'] = i;
            count = count + (1 + std::min({lastSeen[0], lastSeen[1], lastSeen[2]}));

        }
        return count;
    }
};