class Solution {
public:
    bool isPowerOfFour(int n) {
       return __builtin_popcount(n) == 1 && n % 3 == 1; 
    }
};