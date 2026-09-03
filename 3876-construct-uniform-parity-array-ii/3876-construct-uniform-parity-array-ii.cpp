class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int sOdd = INT_MAX;

        for(int num : nums1){
            if(num % 2 == 1){
                sOdd = min(sOdd, num);
            }
        }

        if(sOdd == INT_MAX) return true;
        for(int num : nums1){
            if(num % 2 == 0 && num <= sOdd) return false;
        }
        return true;
    }
};