class Solution {
public:
    bool isSort(vector<int>& arr){
        for(int i = 0;i < arr.size()-1;i++){
            if(arr[i] > arr[i+1]) return false;
        }
        return true;
    }
 
    int minimumPairRemoval(vector<int>& nums) {
        if(isSort(nums)) return 0;
        int cnt = 0;
        while(true){
            int li = -1, mi = INT_MAX, n = nums.size();
            for(int i = 0;i < n-1;i++){
                if(nums[i] + nums[i+1] < mi){
                    li = i;
                    mi = nums[i] + nums[i+1];
                }
            }

            vector<int> temp(n - 1);
            int j = 0;

            for(int i = 0;i < n;i++){
                if(i == li){
                    temp[j] = nums[i] + nums[i+1];
                    j++;
                    i++;
                } else {
                    temp[j] = nums[i];
                    j++;
                }
            }
            nums = temp;
            cnt++;
            if(isSort(nums)) break;
        }
        return cnt;
        
    }
};