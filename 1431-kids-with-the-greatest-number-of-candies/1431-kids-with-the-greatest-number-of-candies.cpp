class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(), candies.end());

        vector<bool> ans;

        for(int num : candies){
            ans.push_back(num + extraCandies >= maxi);
        }

        return ans;
    }
};