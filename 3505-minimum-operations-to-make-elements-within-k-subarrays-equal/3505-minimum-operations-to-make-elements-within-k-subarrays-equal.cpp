class Solution {
public:
    using ll = long long;

    multiset<int> low, high;
    ll sumLow = 0, sumHigh = 0;

    void balance() {
        while (low.size() > high.size() + 1) {
            int val = *low.rbegin();
            low.erase(prev(low.end()));
            sumLow -= val;

            high.insert(val);
            sumHigh += val;
        }

        while (low.size() < high.size()) {
            int val = *high.begin();
            high.erase(high.begin());
            sumHigh -= val;

            low.insert(val);
            sumLow += val;
        }
    }

    void add(int val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            sumLow += val;
        }
        else {
            high.insert(val);
            sumHigh += val;
        }

        balance();
    }

    void remove(int val) {
        auto it = low.find(val);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= val;
        }
        else {
            it = high.find(val);
            high.erase(it);
            sumHigh -= val;
        }

        balance();
    }

    ll getCost() {
        ll median = *low.rbegin();

        ll leftCost = median * low.size() - sumLow;
        ll rightCost = sumHigh - median * high.size();

        return leftCost + rightCost;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<ll> cost;

        // Step 1: Calculate cost of every window
        low.clear();
        high.clear();
        sumLow = sumHigh = 0;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost.push_back(getCost());
            }
        }

        // Step 2: Dynamic Programming
        const ll INF = 1e18;

        vector<vector<ll>> dp(
            k + 1, vector<ll>(n + 1, INF)
        );

        // Selecting zero windows costs zero
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int t = 1; t <= k; t++) {
            for (int i = 1; i <= n; i++) {

                // Choice 1: Skip current element
                dp[t][i] = dp[t][i - 1];

                // Choice 2: Take window ending here
                if (i >= x) {
                    dp[t][i] = min(
                        dp[t][i],
                        dp[t - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};