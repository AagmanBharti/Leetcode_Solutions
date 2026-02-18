class Solution {
public:
    vector<int> diStringMatch(string s) {
        int maxi = s.length(), mini = 0;
        vector<int> ans{};
        for(char ch : s)
            if(ch == 'D')
                ans.push_back(maxi--);
            else
                ans.push_back(mini++);
        if(s.length()-1 == 'D')
            ans.push_back(maxi--);
        else
            ans.push_back(mini++);
        return ans;
    }
};