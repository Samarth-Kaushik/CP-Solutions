class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }
        int cnt = 0;
        for(auto it : mpp){
            vector<int> v = it.second;
            if(v.size() != 3) continue;
            int diff = v[1] - v[0];
            if(v[2] - v[1] == diff){
                cnt++;
            }
        }
        return cnt;
    }
};