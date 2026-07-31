class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for(char ch : word){
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end());

        int minPush = 0;

        for(int i = 25, pushCount = 0; i >= 0; i--){
            int currIdx = 25 - i;
            if(currIdx % 8 == 0) pushCount++;

            minPush += freq[i] * pushCount;
        }

        return minPush;
    }
};