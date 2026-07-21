class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for(char c : s){
            if(c == '1') ones++;
        }

        s = "1" + s + "1";
        int n = s.size();
        int i = 0;
        int ans = ones;

        while(i < n && s[i] == '1') i++;
        int c0 = 0;
        while(i < n && s[i] == '0'){
            c0++;
            i++;
        }

        while(i < n){
            int c1 = 0;
            while(s[i] == '1'){
                c1++;
                i++;
            }

            if(c1 == 0) break;

            int c2 = 0;
            while(s[i] == '0'){
                c2++;
                i++;
            }

            if(c2 == 0) break;

            ans = max(ans, ones + c0 + c2);
            c0 = c2;
        }

        return ans;
    }
};