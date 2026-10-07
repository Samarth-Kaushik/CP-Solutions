
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;
        
        // Step 1: Count minimum left and right parentheses to remove
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) {
                    left_rem--; // A matching pair is found
                } else {
                    right_rem++; // Unmatched right parenthesis
                }
            }
        }
        
        vector<string> result;
        dfs(s, 0, left_rem, right_rem, result);
        return result;
    }

private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            
            // If right parentheses ever outnumber left, it's invalid
            if (count < 0) return false; 
        }
        return count == 0;
    }

    void dfs(string s, int start, int l, int r, vector<string>& result) {
        // Base case: If no more parentheses to remove, check validity
        if (l == 0 && r == 0) {
            if (isValid(s)) {
                result.push_back(s);
            }
            return;
        }

        for (int i = start; i < s.length(); i++) {
            // Prune duplicate branches
            if (i != start && s[i] == s[i - 1]) continue;

            // Try removing a right parenthesis
            if (r > 0 && s[i] == ')') {
                string next_str = s.substr(0, i) + s.substr(i + 1);
                dfs(next_str, i, l, r - 1, result);
            }
            // Try removing a left parenthesis
            else if (l > 0 && s[i] == '(') {
                string next_str = s.substr(0, i) + s.substr(i + 1);
                dfs(next_str, i, l - 1, r, result);
            }
        }
    }
};