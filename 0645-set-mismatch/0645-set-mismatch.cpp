class Solution {
public:
vector<int> findErrorNums(vector<int>& nums) {
    int duplicate = -1, missing = -1;

    // Mark visited numbers by turning them negative
    for (int num : nums) {
        int idx = abs(num) - 1;
        if (nums[idx] < 0)
            duplicate = abs(num);
        else
            nums[idx] *= -1;
    }

    // The index with positive value corresponds to the missing number
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    return {duplicate, missing};
}
};