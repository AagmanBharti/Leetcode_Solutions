
class Solution {
public:
    int minChanges(string s) {
        vector<string> temp;

        for(int i = 0; i < s.size(); i += 2) {
            temp.push_back(s.substr(i, 2));
        }

        int changes = 0;

        for(int i = 0; i < temp.size(); i++) {
            string str = temp[i];

            if(str[0] != str[1]) {
                changes++;
            }
        }

        return changes;
    }
};
