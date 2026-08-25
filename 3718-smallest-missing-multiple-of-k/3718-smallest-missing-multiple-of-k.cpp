class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }

        int curr = k;
        while(st.count(curr)){
            curr += k;
        }
        return curr;
    }
};