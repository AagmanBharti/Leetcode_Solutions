class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int res = 0;
        for(char c : s){
            if(c == 'L') balance++;
            if(c == 'R') balance--;
            if(balance == 0) res++;
        }
    return res;
    }
};