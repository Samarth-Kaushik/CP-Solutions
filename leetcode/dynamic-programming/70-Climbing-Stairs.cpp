class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n <= 1 || dp[n] != -1) return dp[n];
        int left = solve(n-1, dp);
        int right = solve(n-2, dp);
        return dp[n] = left + right;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        // dp[2] = 2;
        int cnt = solve(n, dp);
        return cnt;
    }
};