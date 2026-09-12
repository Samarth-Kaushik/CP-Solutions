class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }
        int cnt = 0;
        for(auto it : mpp){
            vector<int> v = it.second;
            if(v.size() < 3) continue;
            bool isPoss = true;
            int diff;
            for(int i = 0; i < v.size(); i++){
                if(i == 0) diff = v[1] - v[0];
                if(i > 0){
                    if(v[i] - v[i-1] != diff){
                        isPoss = false;
                        break;
                    }
                }
            }
            if(isPoss) cnt++;
        }
        return cnt;
    }
};