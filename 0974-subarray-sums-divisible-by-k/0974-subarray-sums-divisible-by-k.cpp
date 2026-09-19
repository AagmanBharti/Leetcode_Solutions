class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int prefix = 0;
        int cnt = 0;

        for(int x : nums){
            prefix += x;

            int rem = prefix % k;
            if(rem < 0) rem += k;
            if(freq.count(rem)) cnt += freq[rem];

            freq[rem]++;
        }
        return cnt;
    }
};