class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int k){
        long long hours = 0;

        for(int bananas : piles){
            hours += (bananas + k - 1) / k;

            if(hours > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(piles, h, mid)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};