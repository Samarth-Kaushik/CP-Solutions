class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int ans = INT_MIN;
        for(int i = 1; i < n; i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] = 2;
                    if(i >= 2){
                        dp[i] = dp[i] + dp[i-2];
                    }
                }
                else{
                    int jInd = i - dp[i-1] - 1;
                    if(jInd >= 0 && s[jInd] == '('){
                        dp[i] = 2 + dp[i-1];
                        if(jInd >= 1){
                            dp[i] = dp[i] + dp[jInd-1];
                        }
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        if(ans == INT_MIN) return 0;
        return ans;
    }
};