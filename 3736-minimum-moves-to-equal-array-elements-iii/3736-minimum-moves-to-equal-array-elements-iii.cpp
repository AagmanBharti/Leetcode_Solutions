class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maximum = *max_element(nums.begin(), nums.end());

        int moves = 0;
        for(int num : nums){
            moves += abs(num - maximum);
        }
        return moves;
    }
};