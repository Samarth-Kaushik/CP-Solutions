class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if(s.length() == 1){
            if(k == 1 && s[0] == '1') return s;
            else return "";
        }
        vector<string> ans;
        // string temp = "";
        int left = 0;
        int right = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        while(right < s.length()){
            if(s[right] == '1') cnt++;
            if(cnt == k){
                int len = right -left + 1;
                minLen = min(len, minLen);
                ans.emplace_back(s.substr(left, len));
            };
            while(cnt >= k || s[left] == '0'){
                if(s[left] == '1') cnt--;
                left++;
            }
            right++;
        }
        for(int i = 0; i < ans.size(); i++){
            if(ans[i].length() != minLen){
                ans[i] = "";
            }
        }
        sort(ans.begin(), ans.end());
        for(auto it : ans){
            if(it != "") return it;
        }
        return "";
    }
};