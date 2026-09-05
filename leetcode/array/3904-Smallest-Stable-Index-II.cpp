class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n, 0);
        vector<int> mini(n, 0);
        int mini1 = INT_MAX;
        int maxi1 = -1;
        for(int i = 0; i < n; i++){
            mini1 = min(mini1, nums[n - 1 - i]);
            maxi1 = max(maxi1, nums[i]);
            maxi[i] = maxi1;
            mini[n-1-i] = mini1;
        }
        for(int i = 0; i < n; i++){
            if((maxi[i] - mini[i]) <= k) return i;
        }
        return -1;
    }
};