class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(') st.push(s[i]);
            else{
                if(!st.empty()){
                    st.pop();
                }else cnt++;
            }
        }
        int temp = st.size();
        return abs(temp+cnt);
    }
};