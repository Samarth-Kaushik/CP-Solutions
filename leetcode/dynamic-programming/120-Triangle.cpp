class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    //     int m = triangle.size();
    //     int n = triangle[0].size();
    //     if(i == m-1) return dp[i][j] = triangle[i][j];
    //     if(dp[i][j] != INT_MIN) return dp[i][j];
    //     int bottom = INT_MAX, right = INT_MAX;
    //     bottom = triangle[i][j] + solve(i+1, j, triangle, dp);
    //     right = triangle[i][j] + solve(i+1, j+1, triangle, dp);
    //     return dp[i][j] = min(right, bottom);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MIN));
        for(int i = 0; i < n; i++){
            dp[m-1][i] = triangle[m-1][i];
        }
        for(int i = m-2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                int up = triangle[i][j] + dp[i+1][j];
                int right = INT_MAX;
                right = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(right, up);
            }
        }
        return dp[0][0];
        // return solve(0, 0, triangle, dp);
    }
};