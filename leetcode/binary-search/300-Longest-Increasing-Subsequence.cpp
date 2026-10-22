class Solution {
public:
    int solve(int ind, vector<int>& nums, int prevInd, vector<vector<int>>& dp){
        int n = nums.size();
        if(ind >= n) return 0;
        if(dp[ind][prevInd+1]  != -1) return dp[ind][prevInd+1];
        int notTake = solve(ind+1, nums, prevInd, dp);
        int take = 0;
        if(prevInd == -1 || nums[ind] > nums[prevInd]){
            take = 1 + solve(ind+1, nums, ind, dp);
        }
        return dp[ind][prevInd+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, nums, -1, dp);
    }
};