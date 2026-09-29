class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& grid, int cnt, vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        
        if(i >= n || j >= m){
            return false;
        }
        if(grid[i][j] == '(') cnt++;
        else cnt--;
        if(cnt < 0) return false;
        if(i == n - 1 && j == m - 1) return cnt == 0;
        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];
        bool right = solve(i+1, j, grid, cnt, dp);
        bool bottom = solve(i, j+1, grid, cnt, dp);
        return dp[i][j][cnt] = (right || bottom);
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == ')' || grid[n-1][m-1] == '(') return false;

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m+n, -1))
        );
        
        return solve(0, 0, grid, 0, dp);
    }
};