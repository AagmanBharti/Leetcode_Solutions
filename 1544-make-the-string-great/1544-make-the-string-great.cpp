class Solution {
public:
    string makeGood(string s) {
        for(int i = 0;i<s.size();i++){
            if(s[i] - s[i+1] == 32 || s[i] - s[i+1] == -32){
                s.erase(i,2);
                i = -1;
            }
        }
        return s;
    }
};