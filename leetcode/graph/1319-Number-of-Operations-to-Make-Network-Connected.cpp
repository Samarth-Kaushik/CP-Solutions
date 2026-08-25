class Solution {
public:
    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int node){
        visited[node] = true;
        for(int next : adjList[node]){
            if(!visited[next]) dfs(adjList, visited, next);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n-1) return -1;
        vector<bool> visited(n, false);
        vector<vector<int>> adjList(n);
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                ans++;
                dfs(adjList, visited, i);
            }
        }
        return ans-1;
    }
};