class Solution {
public:
    // bool solve(int ind, int sum/2 , vector<int>& nums, vector<vector<int>>& dp){
    //     if(sum/2  == 0) return true;
    //     if(ind == 0) return nums[0] == sum/2 ;
    //     if(dp[ind][sum/2 ] != -1) return dp[ind][sum/2 ];
    //     bool notTake = solve(ind-1, sum/2 , nums, dp);
    //     bool take = false;
    //     if(nums[ind] <= sum/2 ){
    //         take = solve(ind-1, sum/2 -nums[ind], nums, dp);
    //     }
    //     return dp[ind][sum/2 ] = take || notTake;
    // }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        int n = nums.size();
        if(sum&1) return false;
        // vector<vector<int>> dp(n, vector<int>(sum/2 +1, 0));
        vector<int> prev(sum/2 +1, 0), curr(sum/2 +1, 0);

        prev[0] = curr[0] = 1;
        if(nums[0] <= sum/2) prev[nums[0]] = 1;
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= sum/2; target++){
                bool notTake = prev[target];
                bool take = false;
                if(nums[ind] <= target){
                    take = prev[target-nums[ind]];
                }
                curr[target] = take||notTake;
            }
            prev = curr;
        }
        return prev[sum/2];
        // return solve(n-1, sum/2, nums, dp);

    }
};