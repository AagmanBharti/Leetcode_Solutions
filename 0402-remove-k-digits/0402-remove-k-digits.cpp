class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for (char c : num) {
            while (!st.empty() && st.back() > c && k > 0) {
                st.pop_back();
                k--;
            }

            st.push_back(c);
        }

        while (k > 0) {
            st.pop_back();
            k--;
        }

        // Remove leading zeroes
        int pos = 0;
        while (pos < st.size() && st[pos] == '0') {
            pos++;
        }

        st = st.substr(pos);

        return st.empty() ? "0" : st;
    }
};