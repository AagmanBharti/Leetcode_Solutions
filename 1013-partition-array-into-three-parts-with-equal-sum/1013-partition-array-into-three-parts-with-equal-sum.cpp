class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(int num: arr){
            sum += num;
        }

        if(sum % 3 != 0) return false;
        int part = 0;
        int cnt = 0;
        for(int num : arr){
            part += num;
            if(part == sum/3){
                part = 0;
                cnt++;
                if(cnt == 3) return true;
            }
        }
        return false;
    }
};