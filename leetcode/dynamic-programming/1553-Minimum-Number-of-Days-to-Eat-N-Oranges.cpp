class Solution {
public:
    int solve(int n){
        if(n == 0) return 0;
        int a = n%2 + solve(n/2);
        int b = n%3 + solve(n/3);
        return 1 + min(a, b);
    }
    int minDays(int n) {
        return solve(n)-1;
    }
};