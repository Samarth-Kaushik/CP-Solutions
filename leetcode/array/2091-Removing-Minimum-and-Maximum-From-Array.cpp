class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = (min_element(nums.begin(), nums.end()) - nums.begin());
        int maxi = (max_element(nums.begin(), nums.end()) - nums.begin());
        int n = nums.size();
        int n1 = max(mini, maxi);
        int n2 = min(mini, maxi) + n-n1;
        int n3 = max(n-n1, n-min(mini, maxi));
        int ans = min({n1, n2, n3});
        if(ans == n3) return ans;
        return ans+1; 
    }
};