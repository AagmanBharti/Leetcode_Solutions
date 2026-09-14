class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        // Store frequency, first index and last index
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            if(first.find(nums[i]) == first.end()) {
                first[nums[i]] = i;
            }

            last[nums[i]] = i;
        }

        // Find degree of the array
        int degree = 0;

        for(auto& it : freq) {
            degree = max(degree, it.second);
        }

        // Find shortest subarray having same degree
        int ans = INT_MAX;

        for(auto& it : freq) {
            int num = it.first;

            if(it.second == degree) {
                int len = last[num] - first[num] + 1;
                ans = min(ans, len);
            }
        }

        return ans;
    }
};