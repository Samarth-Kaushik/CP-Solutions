class Solution {
public:
    int numSquares(int n) {
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(n);
        visited[n] = true;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i = 0; i < size; i++){
                int curr = q.front();
                q.pop();
                for(int j = 1; j*j <= curr; j++){
                    int rem = curr - j*j;
                    if(rem == 0){
                        return level;
                    }
                    if(!visited[rem]){
                        visited[rem] = true;
                        q.push(rem);
                    }
                }
            }
        }
        return level;
    }
};