class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;
        while(true){
            if((n-i) > k){
                reverse(s.begin()+i,s.begin()+i+k);
                i += 2*k;
            } else {
                reverse(s.begin()+i,s.end());
                return s;
            }
        }
        return s;
    }
};