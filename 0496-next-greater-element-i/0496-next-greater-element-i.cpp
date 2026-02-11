class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        stack<int> st;

        for(int i=0;i<nums2.size();i++){
            int curr = nums2[i];

            while(!st.empty() && curr > st.top()){
                mpp[st.top()] = curr;
                st.pop();
            }
            st.push(curr);
        }
            while(!st.empty()){
                mpp[st.top()] = -1;
                st.pop();
            }

        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(mpp[x]);
        }
        return ans;
        
    }
};