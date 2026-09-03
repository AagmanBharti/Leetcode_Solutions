class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int pos = 0;

        while(idx < chars.size()){
            char ch = chars[idx];
            int count = 0;

            while(idx < chars.size() && chars[idx] == ch){
                count++;
                idx++;
            }

            chars[pos++] = ch;

            if(count > 1){
                for(char digit : to_string(count)){
                    chars[pos++] = digit;
                }
            }
        }
        return pos;
    }
};