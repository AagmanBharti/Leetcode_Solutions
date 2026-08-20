class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int count = 0;
        int n = g.size(), m = s.size();
        int i =0, j = 0;

        while(i < n && j < m){
            if(s[j] >= g[i]){
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};