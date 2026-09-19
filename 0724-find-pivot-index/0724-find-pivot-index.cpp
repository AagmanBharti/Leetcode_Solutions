class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }

        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (prefix[i] == suffix[i + 1]) {
                idx = i;
                break;
            }
        }

        return idx == -1 ? -1 : idx;
    }
};