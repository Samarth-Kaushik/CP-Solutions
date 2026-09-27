class Solution {
public:
    // int solve(int ind, int amount, vector<int>&coins, vector<vector<int>>& dp){
    //     if(ind == 0){
    //         if(amount%coins[0] == 0) return dp[ind][amount] = 1;
    //         return dp[ind][amount] = 0;
    //     }
    //     if(amount == 0) return dp[ind][amount] = 1;
    //     if(dp[ind][amount] != -1) return dp[ind][amount];
    //     int notTake = solve(ind-1, amount, coins, dp);
    //     int take = 0;
    //     if(coins[ind] <= amount){
    //         take = solve(ind, amount-coins[ind], coins, dp);
    //     }
    //     return dp[ind][amount] = take+notTake;
    // }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int tar = coins[i]; tar <= amount; tar++){
                dp[tar] = dp[tar] + dp[tar-coins[i]];
            }
        }
        return dp[amount];      
    }
};