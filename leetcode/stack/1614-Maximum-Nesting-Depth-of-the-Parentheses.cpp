class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int depth = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                depth++;
                ans = max(depth, ans);
            }else if(s[i] == ')') depth--;
        }
        return ans;
    }
};