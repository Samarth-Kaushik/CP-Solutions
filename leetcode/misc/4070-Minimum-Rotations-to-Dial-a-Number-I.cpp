class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int curr = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            int target = s[i] - '0';
            int diff = abs(curr - target);
            ans += min(diff, 10 - diff);
            curr = target;
        }
        return ans;
    }
};