class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> len;
        int n = s.size();
        string temp = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '(') len.push(temp.size());
            else if(s[i] == ')'){
                reverse(temp.begin()+len.top(), temp.end());
                len.pop();
            }else temp += s[i];
        }
        return temp;
    }
};