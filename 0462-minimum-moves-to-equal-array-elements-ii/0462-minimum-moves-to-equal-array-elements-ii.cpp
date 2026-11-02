class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int moves = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int median = nums[ceil(n/2)];

        for(int num : nums){
            moves += abs(num - median);
        }
        return moves;
    }
};