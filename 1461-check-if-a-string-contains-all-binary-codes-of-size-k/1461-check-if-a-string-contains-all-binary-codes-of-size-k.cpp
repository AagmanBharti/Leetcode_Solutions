class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = std::pow(2,k);
        unordered_set<string> st;
        for(int i=0;i+k<=s.size();i++){
            st.insert(s.substr(i,k));
        }
        return st.size() == len;
    }
};