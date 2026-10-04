class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openBr;
        stack<int> star;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(') openBr.push(i);
            else if(s[i] == '*') star.push(i);
            else{
                if(!openBr.empty()){
                    openBr.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }else{
                    return false;
                }
            }
        }
        while(!openBr.empty() && !star.empty()){
            if(openBr.top() > star.top()){
                return false;
            }
            openBr.pop();
            star.pop();
        }
        return openBr.empty();
    }
};