class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = find(u);
            int ulp_v = find(v);

            if (ulp_u == ulp_v)
                return;

            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU ds(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (ds.find(u) == ds.find(v))
                return edge;

            ds.unionBySize(u, v);
        }

        return {};
    }
};