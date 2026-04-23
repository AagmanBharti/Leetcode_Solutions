class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;
        for(int num : nums){
            if(num == 0 && digit == 0){
                cnt++;
                continue;
            }

            while(num > 0){
                if(num % 10 == digit){
                    cnt++;
                }
                num /= 10;
            }

        }
        return cnt;
    }
};