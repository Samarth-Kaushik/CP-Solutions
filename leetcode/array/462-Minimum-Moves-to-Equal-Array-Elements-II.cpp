class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target = nums[n/2];
        int moves = 0;
        for(int x : nums){
            moves += abs(x-target);
        }
        return moves;
    }
};