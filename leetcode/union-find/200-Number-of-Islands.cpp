class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};