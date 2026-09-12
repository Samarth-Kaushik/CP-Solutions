class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // dp[0][0] = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[j] = dp[j-1] + dp[j];
            }
        }

        return dp[n-1];
    }
};