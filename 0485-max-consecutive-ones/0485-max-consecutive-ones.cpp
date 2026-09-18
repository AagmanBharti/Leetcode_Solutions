class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxOnes = 0;

        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] == 1) {
                cnt++;
                maxOnes = max(maxOnes, cnt);
            }
            else {
                cnt = 0;
            }
        }

        return maxOnes;
    }
};