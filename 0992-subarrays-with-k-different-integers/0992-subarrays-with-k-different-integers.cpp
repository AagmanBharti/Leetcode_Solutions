class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        int left = 0;
        int cnt = 0;

        for (int right = 0; right < nums.size(); right++) {
            mpp[nums[right]]++;

            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);
                left++;
            }

            cnt += right - left + 1;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};