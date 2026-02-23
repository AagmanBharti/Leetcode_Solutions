class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;

        for(auto& ops: operations){
            if(ops == "+")
                ans.push_back(ans.back() + ans[ans.size()-2]);
            else if(ops == "C")
                ans.pop_back();
            else if(ops == "D")
                ans.push_back(ans.back()*2);
            else ans.push_back(stoi(ops));
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};