class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str = "";
        string tr = "";

        for(int i = 0;i < s.size();i++){
            if(s[i] != '#'){
                str += s[i];
            } else {
                if(str != ""){
                    str.pop_back();
                }
            }
        }

        for(int i = 0;i < t.size();i++){
            if(t[i] != '#'){
                tr += t[i];
            } else {
                if(tr != ""){
                    tr.pop_back();
                }
            }
        }
        return str == tr;
    }
};