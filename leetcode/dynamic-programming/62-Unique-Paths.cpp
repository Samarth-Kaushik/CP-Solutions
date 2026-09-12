class Solution {
public:
    int solve(int i, int j, vector<int>& dp, int n){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i*n+j] != -1) return dp[i*n+j];
        int down = solve(i-1, j, dp, n);
        int right = solve(i, j-1, dp, n);
        return dp[i*n+j] = (down + right);
    }
    int uniquePaths(int m, int n) {
        vector<int> dp(m*n, -1);
        return solve(m-1, n-1, dp, n);
        // return dp[0];
    }
};