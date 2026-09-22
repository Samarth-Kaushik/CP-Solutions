class Solution {
public:
    // bool solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
    //     if(target == 0) return true;
    //     if(ind == 0) return nums[0] == target;
    //     if(dp[ind][target] != -1) return dp[ind][target];
    //     bool notTake = solve(ind-1, target, nums, dp);
    //     bool take = false;
    //     if(nums[ind] <= target){
    //         take = solve(ind-1, target-nums[ind], nums, dp);
    //     }
    //     return dp[ind][target] = take || notTake;
    // }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        int n = nums.size();
        if(sum&1) return false;
        vector<vector<int>> dp(n, vector<int>(sum/2 +1, 0));
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        if(nums[0] <= sum/2) dp[0][nums[0]] = 1; 
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= sum/2; target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(nums[ind] <= target){
                    take = dp[ind-1][target - nums[ind]];
                }
                dp[ind][target] = take||notTake;
            } 
        }
        return dp[n-1][sum/2];
        // return solve(n-1, sum/2, nums, dp);

    }
};