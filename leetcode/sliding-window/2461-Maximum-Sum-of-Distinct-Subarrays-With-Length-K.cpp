class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        long long sum = 0;
        int i = 0, j= 0;
        unordered_set<int> s;
        while(j < n){
            while(s.count(nums[j])){
                sum -= nums[i];
                s.erase(nums[i]);
                i++;
            }
            sum += nums[j];
            s.insert(nums[j]);
            while(j-i+1 > k){  
                sum -= nums[i];
                s.erase(nums[i]);
                i++;
            }
            if(j-i+1 == k){
                ans = max(ans, sum);
            }
            j++;
        }
        return ans;
    }
};