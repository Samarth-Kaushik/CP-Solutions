class Solution {
    vector<int> primes(int n){
        vector<int> arr;
        if(n <= 1) return arr;
        if(n % 2 == 0){
            arr.push_back(2);
            while(n % 2 == 0){
                n /= 2;
            }
        }
        for(int i = 3; i * i <= n; i++){
            if(n % i == 0) arr.push_back(i);
            while(n % i == 0){
                n /= i;
            }
        }
        if(n > 1) arr.push_back(n);
        return arr;
    }
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> factors(n+1);
        for(int i = 0; i < n; i++){
            factors[i] = primes(nums[i]);
        }
        unordered_map<int, int> mpp;
        int k1 = 0;
        int maxi = 0;
        int left = 0;
        for(int i = 0; i < n; i++){
            for(int num : factors[i]){
                if(mpp[num] == 0){
                    k1++;
                    // maxi = max(maxi, i-left+1);
                }
                mpp[num]++;
            }
                 while(k1 > k){
                    for(int num :factors[left]){
                        if(mpp[num] != 0){
                            mpp[num]--;
                            if(mpp[num] == 0){
                                k1--;
                            }
                        }
                    }
                    left++;
                }
            maxi = max(maxi, i-left+1);
        }
        return maxi; 
    }
};