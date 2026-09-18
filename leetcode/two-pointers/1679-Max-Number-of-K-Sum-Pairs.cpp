class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        int j = n-1;
        int sum = 0;
        int op = 0;
        while(j > i){
            sum = nums[j] + nums[i];
            if(sum == k){
                op++;
                i++;
                j--;
            }
            else if(sum < k){
                i++;
            }
            else j--;
        }
        return op;
    }
};