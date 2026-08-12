class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int n = fruits.size();
        int left = 0;

        unordered_map<int, int> freq;

        for(int right = 0; right < n; right++){
            freq[fruits[right]]++;

            if(freq.size() > 2){
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0) freq.erase(fruits[left]);
                left++;
            }

            if(freq.size() <= 2) ans = max(ans, right - left + 1);
        }
        return ans;
    }
};