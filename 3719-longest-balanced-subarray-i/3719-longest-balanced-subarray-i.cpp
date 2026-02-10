class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int result = 0;
        unordered_set<int> odd,even;
        for(int i=0;i<nums.size();i++){
            odd.clear();
            even.clear();
            for(int j=i;j<nums.size();j++){
                int num = nums[j];
                if((num % 2) == 1) odd.insert(num);
                else even.insert(num);
                if(odd.size() == even.size()){
                    result = max(result, j - i + 1);
                }
            }
       }
       return result;
    }
};