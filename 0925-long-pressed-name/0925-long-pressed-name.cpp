class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;

        while(j < typed.size()) {

            // Match current character
            if(i < name.size() && name[i] == typed[j]) {
                i++;
                j++;
            }
            // Extra repeated character in typed
            else if(j > 0 && typed[j] == typed[j - 1]) {
                j++;
            }
            // Invalid character
            else {
                return false;
            }
        }

        return i == name.size();
    }
};