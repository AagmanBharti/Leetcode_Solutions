class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefSum(n+1,0);
        int res = INT_MAX;

        for(int i= 0;i< n;i++){
            prefSum[i+1] = prefSum[i] + nums[i];
        }

        deque<int> dq;

        for(int i = 0;i <= n;++i){
            while(!dq.empty() && prefSum[i] - prefSum[dq.front()] >= k){
                res = min(res,i - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefSum[i] <= prefSum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return res == INT_MAX ? -1 : res;
    }
};