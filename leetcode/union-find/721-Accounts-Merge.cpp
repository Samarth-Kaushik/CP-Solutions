class Disjointset {
    vector<int> parent;
    vector<int> size;

public:
    Disjointset(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts
    ) {
        int n = accounts.size();

        Disjointset ds(n);
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; i++) {

            int m = accounts[i].size();

            for (int j = 1; j < m; j++) {

                string mail = accounts[i][j];

                if (mpp.find(mail) == mpp.end()) {
                    mpp[mail] = i;
                }
                else {
                    ds.unionBySize(i, mpp[mail]);
                }
            }
        }
        vector<vector<string>> v(n);

        for (auto it : mpp) {

            string mail = it.first;
            int accountIndex = it.second;

            int node = ds.findUPar(accountIndex);

            v[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (v[i].empty())
                continue;
            sort(v[i].begin(), v[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto &mail : v[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};