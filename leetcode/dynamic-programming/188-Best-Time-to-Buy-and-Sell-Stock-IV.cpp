class Solution {
public:
    int solve(int ind, vector<int>&prices, int buy, int k, vector<vector<vector<int>>>& dp){
        int n = prices.size();
        if(ind >= n) return 0;
        if(k == 0) return 0;
        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];
        if(buy){
            return dp[ind][buy][k] = max(-prices[ind]+solve(ind+1, prices, 0, k, dp), solve(ind+1, prices, 1, k, dp));
        }else{
            return dp[ind][buy][k] = max(prices[ind]+solve(ind+1, prices, 1, k-1, dp), solve(ind+1, prices, 0, k, dp));
        }
        return dp[ind][buy][k] = 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, prices, 1, k, dp);
    }
};