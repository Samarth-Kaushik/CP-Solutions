class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowCnt(m+1, 0);
        vector<int> colCnt(n+1, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && (rowCnt[i] > 1 || colCnt[j] > 1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};