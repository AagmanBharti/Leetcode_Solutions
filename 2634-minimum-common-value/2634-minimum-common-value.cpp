class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int res = INT_MAX;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                res = nums1[i];
                break;
            } else if(nums1[i]<nums2[j]){
                i++;
            } else {
                j++;
            }
        }
        return res != INT_MAX ? res:-1;
    }
};