class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if(s.length() == 1){
            if(k == 1 && s[0] == '1') return s;
            else return "";
        }
        string best = "";
        int n = s.size();
        int r = 0, l = 0;
        int cnt = 0;
        
        while(r < n){
            if(s[r] == '1') cnt++;
            
            while(cnt >= k){
                int current_len = r - l + 1;
                string current_str = s.substr(l, current_len);
                
                if(best == "" || best.length() > current_len || 
                  (best.length() == current_len && current_str < best)){
                    best = current_str;
                }
                
                if(s[l] == '1') cnt--;
                l++;
            }
            r++;
        }
        
        return best;
    }
};