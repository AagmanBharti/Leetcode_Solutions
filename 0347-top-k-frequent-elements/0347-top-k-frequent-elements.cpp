class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto& [num, frequency] : freq){
            pair<int, int> newPair = {frequency, num};
            if(pq.size() < k) pq.push(newPair);
            else {
                pq.push(newPair);
                pq.pop();
            }
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};