class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int n1 = -1, n2 = -1;
            if(i > 0){
                n1 = nums[i-1];
            }
            if(i < n-1){
                n2 = nums[i+1];
            }
            float avg = 0;
            if(n1 == -1 || n2 == -1){
                avg = (n1 == -1)? n2 : n1;
            }
            else avg = (n1 + n2)/2.0;
            if(nums[i] >= avg) cnt++;
        }
        return cnt;
    }
};