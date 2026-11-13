class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string word = q.front().first;
                int steps = q.front().second;
                q.pop();
                if(word == endWord) return steps;
                for(int j = 0; j < word.size(); j++){
                    char original = word[j];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        word[j] = ch;
                        if(st.find(word) != st.end()){
                            st.erase(word);
                            q.push({word, steps+1});
                        }
                    }
                    word[j] = original;
                }
            }
        }
        return 0;
    }
};