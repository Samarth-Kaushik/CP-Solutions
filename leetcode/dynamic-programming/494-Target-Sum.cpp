class Solution {
public:
    int solve(int ind, int target, vector<int>& nums){
        if(ind < 0){
            if(target == 0) return 1;
            return 0;
        }
        int add = solve(ind-1, target+nums[ind], nums);
        int sub = solve(ind-1, target-nums[ind], nums);
        return (add+sub);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n-1, target, nums);
    }
};