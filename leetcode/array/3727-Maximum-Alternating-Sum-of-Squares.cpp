class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> val;
        for(int x : nums){
            val.push_back(x*x);
        }
        sort(val.begin(), val.end());
        long long ans = 0;
        int n = val.size();
        for(int i = 0; i < n; i++){
            if(i < n/2){
                ans -= val[i];
            }else ans += val[i];
        }
        return ans;
    }
};