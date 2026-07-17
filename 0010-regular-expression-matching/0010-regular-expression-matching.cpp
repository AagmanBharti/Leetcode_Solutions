class Solution {
public:
    bool func(int i, int j, string &s, string &p){

        if(i < 0 && j < 0) return true;

        if(j < 0) return false;

        if(i < 0){
            while(j >= 0){
                if(p[j] == '*')
                    j -= 2;
                else
                    return false;
            }
            return true;
        }

        if(p[j] == '.' || s[i] == p[j]) return func(i-1,j-1,s,p);

        if(p[j] == '*'){

            // zero occurrence
            bool notTake = func(i,j-2,s,p);

            // one or more occurrences
            bool take = false;

            if(p[j-1]=='.' || p[j-1]==s[i])
                take = func(i-1,j,s,p);

            return take || notTake;
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return func(s.size()-1,p.size()-1,s,p);
    }
};