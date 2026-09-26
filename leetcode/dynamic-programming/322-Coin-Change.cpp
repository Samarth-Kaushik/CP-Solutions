class Solution {
public:
    // int solve(int ind, int amount, vector<int>& coins){
    //     if(ind == 0){
    //         if(amount % coins[0] == 0){
    //             return amount/coins[0];
    //         }else return 1e9;
    //     }
    //     int notTake = solve(ind-1, amount, coins);
    //     int take = INT_MAX;
    //     if(coins[ind]<= amount){
    //         take = 1 + solve(ind, amount-coins[ind], coins);
    //     }
    //     return min(take, notTake);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans = solve(n-1, amount, coins);
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int i = 1; i <= amount; i++){
            if(i%coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }
        for(int i = 1; i < n; i++){
            for(int tar = 0; tar <= amount; tar++){
                int notTake = dp[i-1][tar];
                int take = INT_MAX;
                if(coins[i] <= tar){
                    take = 1 + dp[i][tar-coins[i]];
                }
                dp[i][tar] = min(take , notTake);
            }
        }
        if(dp[n-1][amount] == 1e9) return -1;
        return dp[n-1][amount];
    }
};