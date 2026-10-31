class Solution {
    int MOD = 1e9+7;
public:
    long long solve(int i , int j, int dir, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        int ans = 0;
        if(dir == 2 || grid[i][j] == 0){
            ans = (ans + solve(i+1, j, 0, grid, dp))%MOD;
            ans = (ans + solve(i, j+1, 1, grid, dp))%MOD;
        }
        else{
            if(dir == 0){
                ans += solve(i, j+1, 1, grid, dp)%MOD;
            }else ans += solve(i+1, j, 0, grid, dp)%MOD;
        }
        return dp[i][j][dir] = ans;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1)));
        return (solve(0, 0, 2, grid, dp));
    }
};