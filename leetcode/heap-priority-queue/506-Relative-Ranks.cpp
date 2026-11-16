class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> copy(score.begin(), score.end());
        sort(copy.rbegin(), copy.rend());
        unordered_map<int, int> mpp;
        int n = score.size();
        for(int i = 0; i < n; i++){
            mpp[copy[i]] = i;
        }
        vector<string> ans;
        for(int x : score){
            int ind = mpp[x];
            if(ind == 0){
                ans.push_back("Gold Medal");
            }
            else if(ind == 1){
                ans.push_back("Silver Medal");
            }
            else if(ind == 2){
                ans.push_back("Bronze Medal");
            }
            else{
                ans.push_back(to_string(ind + 1));
            }
        }
        return ans;
    }
};