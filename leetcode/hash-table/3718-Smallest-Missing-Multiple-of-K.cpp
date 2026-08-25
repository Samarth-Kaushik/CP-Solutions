class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> mul;
        for(int i = 0; i < n; i++){
            if(nums[i] % k == 0){
                mul.insert(nums[i]);
            }
        }
        if(mul.size() == 0) return k;
        int m = mul.size();

        int i = 0;
        for(const auto &it : mul){
            if(it != k*(i+1)) return k*(i+1);
            i++;
        }
        return k*(m+1);
    }
};