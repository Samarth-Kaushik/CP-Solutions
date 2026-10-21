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
        int aheadBuy = 0;
        int aheadNotBuy = 0;
        for(int i = n-1; i >= 0; i--){
            int currBuy = max(-prices[i]+aheadNotBuy, aheadBuy);
            int currNotBuy = max(prices[i]+aheadBuy, aheadNotBuy);
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
};