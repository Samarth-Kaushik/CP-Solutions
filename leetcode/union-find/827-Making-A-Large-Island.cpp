class disjointSet{
    public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    disjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointSet ds(n*n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                vector<int> dx = {0, 1, 0, -1};
                vector<int> dy = {1, 0, -1, 0};
                for(int k = 0; k < 4; k++){
                    int row = i + dx[k];
                    int col = j + dy[k];
                    if(row >= 0 && row < n && col >= 0 && col < n){
                        if(grid[row][col] == 1){
                            ds.unionBySize(i*n+j, row*n+col); 
                        }
                    }
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) continue;
                vector<int> dx = {0, 1, 0, -1};
                vector<int> dy = {1, 0, -1, 0};
                unordered_set<int> s;
                for(int k = 0; k < 4; k++){
                    int row = i + dx[k];
                    int col = j + dy[k];
                    if(row >= 0 && row < n && col >= 0 && col < n){
                        if(grid[row][col] == 1){
                            s.insert(ds.findUPar(row*n+col));
                        }
                    }
                }
                int area = 1;
                for(auto it : s){
                    area += ds.size[it];
                }
                maxi = max(area, maxi);
            }
        }
        if(maxi == INT_MIN){
            if(grid[0][0] == 1) return n*n;
            return 0;
        }
        return maxi;
    }
};