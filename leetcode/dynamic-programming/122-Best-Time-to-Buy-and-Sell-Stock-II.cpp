class Solution {
public:
    // int profit = -1;
    // int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
    //     int n = prices.size();
    //     if(ind == n) return 0;
    //     if(dp[ind][buy] != -1) return dp[ind][buy];
    //     if(buy){
    //         dp[ind][buy] = max((-prices[ind]+solve(ind+1, 0, prices, dp)) , (solve(ind+1, 1, prices, dp)));
    //     }else{
    //         dp[ind][buy] = max((prices[ind]+solve(ind+1, 1, prices, dp)) , (solve(ind+1, 0, prices, dp)));
    //     }
    //     return dp[ind][buy];
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // bool buy = true;
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        dp[n][1] = dp[n][0] = 0;
        int profit = -1;
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                if(j == 1) dp[i][j] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                else if(j == 0){
                    dp[i][j] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                }
                // profit = max(dp[i][j], profit);
            }
        }

        return dp[0][1];
    }
};