class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;
        map<int, int> mpp;
        for(int x : nums) mpp[x]++;
        for(auto it : mpp){
            int x = it.first;
            int cnt = it.second;
            if(cnt > 0){
                for(int i = 0; i < k; i++){
                    if(mpp[x+i] < cnt){
                        return false;
                    }
                    mpp[x+i] -= cnt;
                }
            }
        }
        return true;
    }
};