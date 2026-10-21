class Solution {
public:
    int profit = -1;
    int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            dp[ind][buy] = max((-prices[ind]+solve(ind+1, 0, prices, dp)) , (solve(ind+1, 1, prices, dp)));
        }else{
            dp[ind][buy] = max((prices[ind]+solve(ind+1, 1, prices, dp)) , (solve(ind+1, 0, prices, dp)));
        }
        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // bool buy = true;
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        dp[n][1] = dp[n][0] = 0;
        return solve(0, 1, prices, dp);
    }
};