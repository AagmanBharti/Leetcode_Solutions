class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {

            unordered_map<int, int> freq;

            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            vector<pair<int, int>> v;

            for (auto& [value, count] : freq) {
                v.push_back({count, value});
            }

            sort(v.begin(), v.end(), [](auto& a, auto& b) {
                if (a.first != b.first)
                    return a.first > b.first;

                return a.second > b.second;
            });

            int sum = 0;
            int take = min(x, (int)v.size());

            for (int j = 0; j < take; j++) {
                int frequency = v[j].first;
                int value = v[j].second;

                sum += frequency * value;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};