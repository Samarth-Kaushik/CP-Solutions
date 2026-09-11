class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1, -1);
        int prev = nums[0];
        int prev2 = 0;
        int curr = 0;
        for(int i = 1; i < n; i++){
            int take = nums[i] + prev2;
            int nottake = prev;
            curr = max(take, nottake);
            prev2 = prev;
            prev = curr;
        }
        // return dp[n-1];
        return prev;
    }
};