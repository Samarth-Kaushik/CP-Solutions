class Solution {
public:
    int countCommas(int n) {
        int temp = n;
        int cnt = 0;
        while(temp != 0){
            temp = temp/10;
            cnt++;
        }
        if(cnt <= 3) return 0;
        if(cnt > 3 && cnt < 5) return (n - 1000)+1;
        return (99001 + (n - 100000));
    }
};