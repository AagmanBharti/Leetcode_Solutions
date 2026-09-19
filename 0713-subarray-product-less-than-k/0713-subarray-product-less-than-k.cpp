class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int cnt = 0;
        int product = 1;

        if(k <= 1) return 0;

        for(int right = 0; right < nums.size(); right++){
            product = product * nums[right];

            while(product >= k){
                product /= nums[left];
                left++;
            }

            cnt += 1 + (right - left);
        }
        return cnt;
    }
};