class Solution {
public:
    // int solve(int ind, vector<int>& prices, int buy, int cap, vector<vector<vector<int>>>& dp){
    //     int n = prices.size();
    //     if(cap == 0 || ind == n) return 0;
    //     if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    //     if(buy){
    //         return dp[ind][buy][cap] = max((-prices[ind]+solve(ind+1, prices, 0, cap, dp)), solve(ind+1,prices, 1, cap, dp));
    //     }else{
    //         return dp[ind][buy][cap] = max((prices[ind]+solve(ind+1, prices, 1, cap-1, dp)), solve(ind+1, prices, 0, cap, dp));
    //     }
    //     return dp[ind][buy][cap]= 0;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        for(int i = 0; i < n; i++){
            dp[i][0][0] = dp[i][1][0] = 0;
        }
        for(int i = 0; i < 3; i++){
            dp[n][0][i] = dp[n][1][i] = 0;
        }
        for(int ind = n-1; ind >= 0; ind--){
            for(int j = 0; j < 2; j++){
                for(int k = 1; k < 3; k++){
                    if(dp[ind][j][k] != -1) continue;
                    if(j == 1){
                        dp[ind][j][k] = max(-prices[ind]+dp[ind+1][0][k], dp[ind+1][1][k]);
                    }else{
                        dp[ind][j][k] = max(prices[ind]+dp[ind+1][1][k-1], dp[ind+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};