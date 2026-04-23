class Solution {
public:
    bool isPrime(int num){
        if(num <= 1) return false;
        for(int i = 2;i*i <= num;i++){
            if(num % i == 0) return false;
        }
        return true;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        for(int i = 0;i<n;i++){
            if(i % 2==0){
                if(isPrime(nums[i])) continue;
                else {
                    int num = nums[i];
                    while(!isPrime(num)){
                        num++;
                        ops++;
                    }
                }
        }
        else {
            if(isPrime(nums[i]) == false){
                continue;
            } else {
                int num = nums[i];
                while(isPrime(num) == true){
                    num++;
                    ops++;
                }
            }
        }
        }
        return ops;
        
    }
};