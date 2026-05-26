class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        unordered_set<char> st(word.begin(), word.end());

        for(char ch = 'a'; ch <= 'z';ch++){
            if(st.count(ch) && st.count(ch - 'a' + 'A')){
                cnt++;
            }
        }

        return cnt;

    }
};