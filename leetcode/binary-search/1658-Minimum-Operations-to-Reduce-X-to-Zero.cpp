class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int num : nums) sum += num;
        int target = sum - x;
        if(target < 0) return -1;
        int i = 0, j = 0;
        int n = nums.size();
        int currSum = 0;
        int maxLen = -1;
        while(j < n){
            currSum += nums[j];
            while(currSum > target && i <= j){
                currSum -= nums[i];
                i++;
            }
            if(currSum == target) maxLen = max(maxLen, j-i+1);
            j++;
        }
        if(maxLen == -1) return maxLen;
        return n-maxLen;
    }
};