class Solution {
public:
    int minOperations(string s) {
        int curr1 = 0,curr2 = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] != (i%2 ? '1' : '0')) curr1++;
            if(s[i] != (i%2 ? '0' : '1')) curr2++;
        }
        return min(curr1,curr2);
    }
};