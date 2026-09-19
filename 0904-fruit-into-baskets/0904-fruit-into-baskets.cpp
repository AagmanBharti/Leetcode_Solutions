class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;

        int left = 0;
        int cnt = 0;

        for(int right = 0; right < fruits.size(); right++){
            freq[fruits[right]]++;

            if(freq.size() > 2){
                while(freq.size() > 2){
                    freq[fruits[left]]--;
                    if(freq[fruits[left]] == 0) freq.erase(fruits[left]);
                    left++;
                }
            }

            if(freq.size() <= 2){
                cnt = max(cnt, right - left + 1);
            }
        }
        return cnt;
    }
};