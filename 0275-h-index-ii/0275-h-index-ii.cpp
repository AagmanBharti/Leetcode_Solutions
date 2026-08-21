class Solution {
public:
    bool count(vector<int>& citations, int h){
        int n = citations.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(citations[i] >= h) cnt++;
        }

        return cnt >= h;
    }

    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        int low = 0;
        int high = n;
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(count(citations, mid)){
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};