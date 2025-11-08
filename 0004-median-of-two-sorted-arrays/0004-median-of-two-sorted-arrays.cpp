class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> temp;

        for(int i=0;i<n1;i++){
            temp.push_back(nums1[i]);
        }
        for(int j=0;j<n2;j++){
            temp.push_back(nums2[j]);
        }

        sort(temp.begin(),temp.end());

        int total = temp.size();
        if(total % 2 == 1){
            return static_cast<double>(temp[total/2]);
        } else {
            int middle1 = temp[total/2 - 1];
            int middle2 = temp[total/2];
            return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2.0;
        }
    }
};