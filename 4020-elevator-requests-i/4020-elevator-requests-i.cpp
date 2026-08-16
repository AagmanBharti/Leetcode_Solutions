class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int total_time = requests[0];

        for(int i = 1;i < requests.size(); i++){
            total_time += abs(requests[i] - requests[i-1]);
        }
        return total_time;
    }
};