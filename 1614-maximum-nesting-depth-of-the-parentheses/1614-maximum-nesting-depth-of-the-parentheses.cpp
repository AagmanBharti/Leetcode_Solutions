class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int max_depth = 0;

        for(char c : s){
            if(c == '('){
                count++;
                if(max_depth < count) max_depth = count;
            }
            else if(c == ')'){
                count--;
            }
        }
        return max_depth;
    }
};