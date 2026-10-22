class Solution {
public:
    // int solve(int ind, int buy, vector<int>& prices, int fee){
    //     int n = prices.size();
    //     if(ind >= n) return 0;
    //     if(buy){
    //         return max(-prices[ind]+solve(ind+1, 0, prices, fee), solve(ind+1, 1, prices, fee));
    //     }else{
    //         return max(prices[ind]+solve(ind+1, 1, prices, fee)-fee, solve(ind+1, 0, prices, fee));
    //     }
    //     return 0;
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                if(j){
                    dp[i][j] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
                }else{
                    dp[i][j] = max(prices[i]-fee+dp[i+1][1], dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};