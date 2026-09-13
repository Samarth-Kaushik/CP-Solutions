class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(i == 0 && j == 0) return dp[0][0] = grid[0][0];
    //     if(i < 0 || j < 0) return 400000;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int up = grid[i][j] + solve(i, j-1, grid, dp);
    //     int left = grid[i][j] + solve(i-1, j, grid, dp);
    //     return dp[i][j] = min(up, left);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[0][0] = grid[0][0];
                else{
                    int up = INT_MAX, left = INT_MAX;
                    if(j > 0) up = grid[i][j] + dp[i][j-1];
                    if(i > 0) left = grid[i][j] + dp[i-1][j];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
        // return solve(m-1, n-1, grid, dp);
    }
};