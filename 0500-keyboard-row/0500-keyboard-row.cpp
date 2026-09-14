class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> row = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };

        vector<string> ans;

        for (string word : words) {
            int r = -1;

            // Find the row of the first character
            char c = tolower(word[0]);

            for (int i = 0; i < 3; i++) {
                if (row[i].find(c) != string::npos) {
                    r = i;
                    break;
                }
            }

            // Check remaining characters
            bool valid = true;

            for (char c : word) {
                c = tolower(c);

                if (row[r].find(c) == string::npos) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans.push_back(word);
        }

        return ans;
    }
};