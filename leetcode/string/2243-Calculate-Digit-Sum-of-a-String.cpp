class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            string nextstr = "";
            for(int i = 0; i < s.length(); i+= k){
                int currSum = 0;
                for(int j = i; j < i + k && j < s.length(); j++){
                    currSum += s[j] - '0';
                }
                nextstr += to_string(currSum);
            }
            s = nextstr;
        }
        return s;
    }
};