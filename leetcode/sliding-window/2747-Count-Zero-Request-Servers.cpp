class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        
        auto lambda = [](const vector<int>& vec1, const vector<int>& vec2){
            return vec1[1] < vec2[1];
        };
        sort(logs.begin(), logs.end(), lambda);
        int q = queries.size();
        vector<int> ans(q);
        vector<pair<int, int>> timeIndex(q);
        for(int i = 0; i < q; i++){
            timeIndex[i] = {queries[i], i};
        }
        sort(timeIndex.begin(), timeIndex.end());
        unordered_map<int, int> mpp;
        int left = 0, right = 0;
        for(auto [time, idx] : timeIndex){
            int start = time - x;
            int end = time;
            while(right < m && logs[right][1] <= end){
                mpp[logs[right][0]]++;
                right++;
            }
            while(left < m && logs[left][1] < start){
                mpp[logs[left][0]]--;
                if(mpp[logs[left][0]] == 0){
                    mpp.erase(logs[left][0]);
                }
                left++;
            }
            ans[idx] = n - mpp.size();
        }

        return ans;    
    }
};