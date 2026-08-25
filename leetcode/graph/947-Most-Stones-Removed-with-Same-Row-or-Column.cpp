class disjointSet{
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    public:
    disjointSet (int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i]= 1;
        }
    }
        int findUPar(int n){
            if(parent[n] == n) return n;
            return parent[n] = findUPar(parent[n]);
        }

        void unionBySize(int n1, int n2){
            int ulp_u = findUPar(n1);
            int ulp_v = findUPar(n2);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            else{
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        // vector<int> v(maxRow+maxCol+1);
        disjointSet ds(maxRow+maxCol+2);
        unordered_map<int, int> mpp;
        for(auto it : stones){
            int row = it[0];
            int col = it[1]+maxRow+1;
            ds.unionBySize(row, col);
            mpp[row] = 1;
            mpp[col] = 1;
        }
        int cnt = 0;
        for(auto it : mpp){
            if(ds.findUPar(it.first) == it.first){
                cnt++;
            }
        }
        return n-cnt;
        
    }
};