class Solution {
public:
    int solve(int n, unordered_map<int, int>& dp){
        if(n <= 1) return n;
        if(dp.find(n) != dp.end()) return dp[n];
        int a = n%2 + 1 + solve(n/2, dp);
        int b = n%3 + 1 + solve(n/3, dp);
        return dp[n] = min(a, b);
    }
    int minDays(int n) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        return solve(n , dp);
    }
};