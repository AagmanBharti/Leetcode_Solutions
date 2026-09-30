class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < tickets.size(); i++) {
            q.push({tickets[i], i});
        }

        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();

            temp.first--;
            count++;

            if (temp.first == 0 && temp.second == k)
                return count;
            if (temp.first > 0)
                q.push(temp);
        }

        return count;
    }
};