class Solution {
public:
    // int solve(int ind, vector<int>& nums, vector<vector<int>>& dp){
    //     int n = nums.size();
    //     if(ind == n-1){

    //     }
    // }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> dp(n, -1);
        int far = 0;
        int jumps = 0;
        int currEnd = 0;
        for(int i = 0; i < n; i++){
            far = max(far, i+nums[i]);
            if(i == currEnd){
                jumps++;
                currEnd = far;
                if(currEnd >= n-1) return jumps;
            }
            
            // if(far >= n-1) return jumps;
        }
        return -1;
    }
};