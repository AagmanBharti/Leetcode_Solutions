class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i + 2 < n; i++) {

            set<char> st;

            st.insert(s[i]);
            st.insert(s[i + 1]);
            st.insert(s[i + 2]);

            if (st.size() == 3) {
                count++;
            }
        }
        return count;
    }
};