class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
                
        vector<vector<int>> store;
        store.reserve(n + 1);
        store.push_back({1});
        store.push_back({1, 1});
        
        for (int i = 2; i <= n; i++)
        {
            vector<int> temp;
            temp.reserve(i + 1);
            temp.push_back(1);
            for (int j = 1; j < i; ++j)
                temp.push_back(store[i - 1][j - 1] + store[i - 1][j]);
        
            temp.push_back(1);
            store.push_back(move(temp));
        }
        return store[n];
    }
};