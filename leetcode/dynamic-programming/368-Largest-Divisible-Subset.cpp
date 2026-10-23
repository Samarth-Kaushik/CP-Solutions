class Solution {
public:
    int solve(int ind, int prevInd, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(ind >= n) return 0;
        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
        int notTake = solve(ind+1, prevInd, nums, dp);
        int take = 0;
        if(prevInd == -1 || nums[ind] % nums[prevInd] == 0){
            take = 1 +  solve(ind+1, ind, nums, dp);
        }
        return dp[ind][prevInd+1] = max(take, notTake);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        solve(0, -1, nums, dp);
        vector<int> lds;
        int prevInd = -1;
        for(int ind = 0; ind < n; ind++){
            int notTake = ((ind+1 < n)? dp[ind+1][prevInd+1] : 0);
            int take = 0;
            if(prevInd == -1 || nums[ind] % nums[prevInd] == 0){
                take = 1 + ((ind+1 < n)? dp[ind+1][ind+1] : 0);   
            }

            if(take > 0 && dp[ind][prevInd+1] == take){
                lds.push_back(nums[ind]);
                prevInd = ind;
            }
        }
        return lds;
    }
};