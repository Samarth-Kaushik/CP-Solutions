class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int evenCnt = 1;
        int oddCnt = 0;
        int runningSum = 0;
        int result = 0;
        for(int x : arr){
            runningSum += x;
            if(runningSum&1){
                result = (result + evenCnt)%MOD;
                oddCnt++;
            }else{
                result = (result + oddCnt)%MOD;
                evenCnt++;
            }
        }
        return result;

    }
};