class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();
        int maxi = 0;

        for(int i = 0;i<n;i++){
            int k = i;
            int count = 0;
            while(k < n){
                string s = sequence.substr(k,m);
                if(s == word){
                    count++;
                    k += m;
                } else {
                    k++;
                    break;
                }
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};