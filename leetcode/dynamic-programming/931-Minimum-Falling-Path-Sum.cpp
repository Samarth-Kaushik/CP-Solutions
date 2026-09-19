class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != INT_MIN) return dp[i][j];
        int st = matrix[i][j] + solve(i-1, j, matrix, dp);
        int left = INT_MAX, right = INT_MAX;
        if(j > 0) left = matrix[i][j] + solve(i-1, j-1, matrix, dp);
        if(j < matrix[i].size() - 1) right = matrix[i][j] + solve(i-1, j+1, matrix ,dp);
        return dp[i][j] = min({st, left, right}); 
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MIN));
        for(int j = 0; j < n; j++){
            mini = min(mini, solve(m-1, j, matrix, dp));
        }
        return mini;
    }
};