class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adjList[u].push_back({v, w});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        pq.push({0, 0, 1});
        dist[0][1] = 0;
        while(!pq.empty()){
            int w = pq.top()[0];
            int u = pq.top()[1];
            int cnt = pq.top()[2];
            pq.pop();
            if(dist[u][cnt] < w) continue;
            if(u == n-1) return w;
            for(auto x : adjList[u]){
                int node = x.first;
                int wt = x.second;
                int newCnt = (labels[u] == labels[node])? cnt+1 : 1;
                if(newCnt <= k && w + wt < dist[node][newCnt]){
                    if(newCnt <= k){
                        dist[node][newCnt] = w+wt;
                        pq.push({w+wt, node, newCnt});
                    }
                }
            }
        }
        return -1;
    }
};