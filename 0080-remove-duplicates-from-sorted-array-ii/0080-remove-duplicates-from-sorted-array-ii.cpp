class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int k = 0;

        for(int num : nums){
            mpp[num]++;

            if(mpp[num] <= 2){
                nums[k] = num;
                k++;
            }
        }
        return k;
    }
};