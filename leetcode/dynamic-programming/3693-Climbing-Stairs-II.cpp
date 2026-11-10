class Solution {
public:
    int solve(int ind, vector<int>& costs, vector<int>& dp, int cost){
        int n = costs.size();
        if(ind >= n) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int minCost = INT_MAX;
        for(int j = 1; j <=3 ; j++){
            int nextStep = ind+j;
            if(nextStep <= n){
                minCost = min(minCost, cost+costs[nextStep-1]+j*j + solve(nextStep, costs, dp, cost));
            } 
        }
        return dp[ind] = minCost;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        return solve(0, costs, dp, 0);
    }
};