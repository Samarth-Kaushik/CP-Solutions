class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        map<int, int> mpp;
        for(int x : hand){
            mpp[x]++;
        }
        for(auto it : mpp){
            int x = it.first;
            int cnt = it.second;
            if(cnt > 0){
                for(int i = 0; i < groupSize; i++){
                    if(mpp[x+i] < cnt){
                        return false;
                    }
                    mpp[x+i] -= cnt;
                }
            }
        }
        return true;
    }
};