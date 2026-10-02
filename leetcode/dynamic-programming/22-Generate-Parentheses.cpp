class Solution {
public:
    void solve(vector<string>& ans, string str, int open, int close){
        if(open == 0 && open == close){
            ans.push_back(str);
            return;
        }
        if(open > 0){
            str += '(';
            solve(ans, str, open-1, close);
            str.pop_back();
        }
        if(close > open && close > 0){
            str += ')';
            solve(ans, str, open, close-1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str= "";
        solve(ans, str, n, n);
        return ans;
    }
};