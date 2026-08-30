class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx  = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        int front = right + 1;
        int back = n - left;

        int frontBack = (left + 1) + (n - right);

        return min({front, back, frontBack});
    }
};