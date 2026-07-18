class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [small, large] = minmax_element(nums.begin(), nums.end());
        return __gcd(*small, *large);
    }
};