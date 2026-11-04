class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> supp(supplies.begin(), supplies.end());
        vector<int> indegree(n, 0);

        unordered_map<string, vector<int>> adj;

        for(int i = 0;i < n;i++){
            for(const string& s : ingredients[i]){
                if(!supp.count(s)){
                    adj[s].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> q;
        for(int i = 0;i < n;i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<string> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            auto s = recipes[node];
            ans.push_back(s);

            for(auto it : adj[s]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        return ans;
    }
};