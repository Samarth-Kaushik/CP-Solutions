class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        vector<string> v;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                i++;
                string temp = "";
                while(s[i] != ')'){
                    temp += s[i];
                    i++;
                }
                v.push_back(temp);
            }
        }
        unordered_map<string, string> mpp;
        sort(v.begin(), v.end());
        sort(knowledge.begin(), knowledge.end());
        for(string str : v) mpp[str] = "?";
        for(int i = 0; i < knowledge.size(); i++){
            mpp[knowledge[i][0]] = knowledge[i][1];
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                string temp = "";
                i++;
                while(s[i] != ')'){
                    temp += s[i];
                    i++;
                }
                ans += (mpp[temp]);
            }
            else ans += s[i];
        }
        return ans;

    }
};