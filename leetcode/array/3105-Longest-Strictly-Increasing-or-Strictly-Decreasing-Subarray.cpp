class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int size1 = 1, size2 = 1;
        int maxi = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                size2 = 1;
                size1++;
                maxi = max({maxi, size1, size2});
            }
            else if(nums[i] > nums[i-1]){
                size1 = 1;
                size2++;
            }
            else{
                size1 = 1, size2 = 1;
            }
            maxi = max({maxi, size1, size2});
        }
        return maxi;
    }
};