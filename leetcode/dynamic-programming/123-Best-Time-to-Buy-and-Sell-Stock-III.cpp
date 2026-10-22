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
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                for(int k = 1; k < 3; k++){
                    if(j){
                        curr[j][k] = max(-prices[i]+ahead[0][k], ahead[1][k]);
                    }else{
                        curr[j][k] = max(prices[i]+ahead[1][k-1], ahead[0][k]);
                    }
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};