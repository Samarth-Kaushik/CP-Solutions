class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        bool flag = false;
        string ans = "";
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                if(flag){
                    ans += s[i];
                }else flag = true;

                cnt++;
            }else{
                if(flag){
                    if(cnt > 1){
                        ans += s[i];
                    }
                }
                if(cnt == 1) flag = false;
                cnt--;
            }
        }
        return ans;
    }
};