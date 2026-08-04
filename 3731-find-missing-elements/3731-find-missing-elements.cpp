class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());
        vector<int> res;
        bool contains[101];

        for(int num : nums){
            contains[num] = true;
        }

        for(int i = smallest; i <= largest; i++){
            if(!contains[i]){
                res.push_back(i);
            }
        }

        return res;

        
    }
};