class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) sum += num;
        
        if(sum < abs(target) || (target + sum) % 2 != 0) return 0;
        
        int s1 = (target + sum) / 2;
        
        vector<vector<int>> dp(n, vector<int>(s1 + 1, 0));
        
        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        if(nums[0] != 0 && nums[0] <= s1) dp[0][nums[0]] = 1;
        
        for(int i = 1; i < n; i++){

            for(int k = 0; k <= s1; k++){
                
                int notTake = dp[i-1][k];
                int take = 0;
                
                if(nums[i] <= k){
                    take = dp[i-1][k - nums[i]];
                }
                
                dp[i][k] = take + notTake;
            }
        }
        
        return dp[n-1][s1];
    }
};