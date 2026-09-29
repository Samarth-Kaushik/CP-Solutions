class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;
        //ind, cnt
        queue<pair<pair<int, int>, int>> q;
        // x, y, cnt
        vector<vector<vector<bool>>> visited(m,
        vector<vector<bool>>(n, vector<bool>(m+n, false)));
        q.push({{0, 0}, 1});
        visited[0][0][1] = true;
        vector<int> dx = {1, 0};
        vector<int> dy = {0, 1};
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto it = q.front();
                if(it.first.first == m-1 && it.first.second == n-1){
                    if(it.second == 0) return true;
                }
                q.pop();
                for(int j = 0; j < 2; j++){
                    int x = it.first.first + dx[j];
                    int y = it.first.second + dy[j];
                    int cnt = it.second;
                    if(x >= 0 && x < m && y >= 0 && y < n){
                        int newCnt = cnt;
                        if(grid[x][y] == '(') newCnt++;
                        else newCnt--;
                        if(newCnt >= 0 && newCnt < (m+n) && !visited[x][y][newCnt]){
                            visited[x][y][newCnt] = true;
                            q.push({{x, y}, newCnt});
                        }
                    }
                }
            }
        }
        return false;
    }
};