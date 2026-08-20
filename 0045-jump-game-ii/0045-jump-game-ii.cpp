class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0, furthest = 0;

        for(int i = 0; i < nums.size()-1; i++){
            furthest = max(furthest, i + nums[i]);

            if(i == currentEnd){
                jumps++;
                currentEnd = furthest;
            }
        }
        return jumps;
    }
};