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
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
            }
        }
        if(dp[amount] >= 1e9) return -1;
        return dp[amount];
    }
};