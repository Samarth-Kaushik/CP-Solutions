class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp){
        int n = prices.size();
        if(ind >= n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy] = max(-prices[ind]+solve(ind+1, 0, prices, fee, dp), solve(ind+1, 1, prices, fee, dp));
        }else{
            return dp[ind][buy] = max(prices[ind]+solve(ind+1, 1, prices, fee, dp)-fee, solve(ind+1, 0, prices, fee, dp));
        }
        return dp[ind][buy] = 0;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // for(int i = n-1; i >= 0; i--){
        //     for(int j = 0; j < 2; j++){
        //         if(j){
        //             dp[i][j] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
        //         }else{
        //             dp[i][j] = max(prices[i]-fee+dp[i+1][1], dp[i+1][0]);
        //         }
        //     }
        // }
        return solve(0, 1, prices, fee, dp);
    }
};