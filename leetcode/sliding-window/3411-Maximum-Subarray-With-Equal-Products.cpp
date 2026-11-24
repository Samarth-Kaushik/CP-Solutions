#include <vector>
#include <numeric>   // std::gcd, std::lcm (C++17)
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        
        // Precompute the upper bound for lcm * gcd to safely prune and avoid overflow
        long long maxVal = 0, totalLcm = 1;
        for (int x : nums) {
            maxVal = max(maxVal, (long long)x);
            totalLcm = lcm(totalLcm, (long long)x);
        }
        long long maxP = totalLcm * maxVal;
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0; // gcd(0, x) == x
            long long l = 1; // lcm(1, x) == x
            
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                
                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
                
                // Stop early: prod will only grow larger and can never match g * l again
                if (prod > maxP) {
                    break;
                }
            }
        }
        
        return ans;
    }
};