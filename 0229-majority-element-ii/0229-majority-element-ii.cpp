class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;

        unordered_map<int, int> freq;
        for(int num : nums) freq[num]++;

        for(auto& [num, times] : freq){
            if(times > floor(nums.size()/3)) res.push_back(num);
        }

        return res;
    }
};