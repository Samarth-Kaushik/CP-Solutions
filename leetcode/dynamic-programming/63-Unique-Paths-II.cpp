class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
    //     int n = obstacleGrid.size();
    //     int m = obstacleGrid[0].size();
    //     //out of bound
    //     if(i < 0 || j < 0 || obstacleGrid[i][j] == 1) return 0;
    //     //base case
    //     if(i == 0 && j == 0) return 1; 
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int up = solve(i, j-1, obstacleGrid, dp);
    //     int left = solve(i-1, j, obstacleGrid, dp);
    //     return dp[i][j] = up + left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int left = 0, down = 0;
                    if(j > 0) down = dp[i][j-1];
                    if(i > 0) left = dp[i-1][j];
                    dp[i][j] = down + left;
                }
            }
        }
        return dp[n-1][m-1];
        // return solve(n-1, m-1, obstacleGrid, dp);
    }
};