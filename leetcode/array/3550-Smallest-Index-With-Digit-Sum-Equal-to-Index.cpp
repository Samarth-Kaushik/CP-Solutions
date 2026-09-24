class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == i && nums[i] < 10){
                ans = i;
                break;
            }
            if(nums[i] >= 10){
                int sum = 0;
                int temp = nums[i];
                while(temp > 0){
                    sum += temp%10;
                    temp /= 10;
                }
                if(sum == i){
                    ans = i;
                    break;
                }
            }
        }
        return ans;
    }
};