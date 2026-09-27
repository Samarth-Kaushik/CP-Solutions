//worm-hole approach

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openBr;
        int n = s.size();
        vector<int> door(n);
        for(int i = 0; i < n; i++){
            if(s[i] == '(') openBr.push(i);
            else if(s[i] == ')'){
                int j = openBr.top();
                openBr.pop();
                door[i] = j;
                door[j] = i;
            }
        }
        int flag = 1;
        string ans = "";
        for(int i = 0; i < n; i += flag){
            if(s[i] == '(' || s[i] == ')'){
                i = door[i];
                flag *= -1;
            }else ans.push_back(s[i]);
        }
        return ans;
    }
};