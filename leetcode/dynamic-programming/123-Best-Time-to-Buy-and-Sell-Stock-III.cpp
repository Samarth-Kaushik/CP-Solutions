class Solution {
public:
    int solve(int ind, vector<int>& prices, int buy, int cap, vector<vector<vector<int>>>& dp){
        int n = prices.size();
        if(cap == 0 || ind == n) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if(buy){
            return dp[ind][buy][cap] = max((-prices[ind]+solve(ind+1, prices, 0, cap, dp)), solve(ind+1,prices, 1, cap, dp));
        }else{
            return dp[ind][buy][cap] = max((prices[ind]+solve(ind+1, prices, 1, cap-1, dp)), solve(ind+1, prices, 0, cap, dp));
        }
        return dp[ind][buy][cap]= 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, prices, 1, 2, dp);
    }
};