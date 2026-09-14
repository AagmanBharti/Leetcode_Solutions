class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        set<int> st;
        for(int candy : candyType){
            st.insert(candy);
        }

        int uniqueCandies = st.size();
        return min(uniqueCandies, n/2);
    }
};