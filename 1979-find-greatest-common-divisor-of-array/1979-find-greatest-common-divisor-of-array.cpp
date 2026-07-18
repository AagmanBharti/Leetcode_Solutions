class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = *min_element(nums.begin(),nums.end());
        int large = *max_element(nums.begin(),nums.end());
        return __gcd(small,large);
    }
};