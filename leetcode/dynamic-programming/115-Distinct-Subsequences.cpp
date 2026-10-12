class Solution {
public:
    int solve(string s, string t, int ind1, int ind2, vector<vector<int>>& dp){
        if(ind2 < 0) return 1;
        if(ind1 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s[ind1] == t[ind2]){
            return dp[ind1][ind2] = solve(s, t, ind1-1, ind2-1, dp) + solve(s, t, ind1-1, ind2, dp);
        }
        return dp[ind1][ind2] = solve(s, t, ind1-1, ind2, dp);
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(s, t, n1-1, n2-1, dp);
    }
};