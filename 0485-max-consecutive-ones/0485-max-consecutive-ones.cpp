class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;

        int i = 0,cnt = 0;
        int j = 0;

        while(j < nums.size()){
            if(nums[j] == 1){
            cnt++;
            maxOnes = max(maxOnes,cnt);
            }

            else if(nums[j] == 0){
                cnt = 0;
                i = j+1;
            }

            j++;
        }
        return maxOnes;
    }
};