class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long powI(long long n1, long long n2){
        long long result = 1.0;
        n1 = n1 %MOD;
        while(n2 > 0){
            if(n2 & 1){
                result = (result * n1)%MOD;
            }
            n1 = (n1 * n1)% MOD;
            n2 >>= 1;
        }
        return result%MOD;
    }
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(long long num : nums){
            int w = num % 10;
            long long d = num/10;
            string s = to_string(d);
            string ans = "";
            ans = s.substr(0, w);
            long long x = stoll(ans);
            ans = "";
            ans = s.substr(w);
            long long y = stoll(ans);
            sum = (sum + powI(x, y));
        }
        return sum % MOD;
    }
};