class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> power(n, 1);
        for(int i = 1; i < n; i++){
            power[i] = (power[i-1]*2)%MOD;
        }
        sort(nums.begin(), nums.end());

        int l = 0, r = n-1;
        int ans = 0;
        while(l <= r){
            if(nums[l] + nums[r] <= target){
                ans = (ans + power[r-l])%MOD;
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};