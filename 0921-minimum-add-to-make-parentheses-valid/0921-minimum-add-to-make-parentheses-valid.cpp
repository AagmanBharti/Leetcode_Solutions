class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int charCount = 0;

        for (char c : s) {
            if (c == '(')
                charCount++;
            if (c == ')') {
                if (charCount == 0)
                    count++;
                else
                    charCount--;
            }
        }
        return count + charCount;
    }
};