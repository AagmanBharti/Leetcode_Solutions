class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        string ans = "";
        for(int i = n-1;i>=0;i--){
            if(!st.empty() && s[i] == st.top()) st.pop();
            else st.push(s[i]);
        }
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        return ans;
    }
};