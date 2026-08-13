class Solution {
public:
    int subarrays(vector<int>& nums, int k){
        int cnt = 0;
        int left = 0;

        unordered_map<int, int> mpp;

        for(int right = 0; right < nums.size(); right++){
            mpp[nums[right]]++;

            while(mpp.size() > k){
                mpp[nums[left]]--;

                if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }

            cnt += right - left + 1;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrays(nums, k) - subarrays(nums, k-1);
    }
};