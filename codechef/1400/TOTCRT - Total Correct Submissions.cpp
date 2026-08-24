#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<string, int> mpp;
        for(int i = 0; i < n; i++){
            string s; int m;
            cin >> s >> m;
            mpp[s] += m;
        }
        for(int i = 0; i < n; i++){
            string s; int m;
            cin >> s >> m;
            mpp[s] += m;
        }
        for(int i = 0; i < n; i++){
            string s; int m;
            cin >> s >> m;
            mpp[s] += m;
        }
        vector<int> scores;
        for(auto it : mpp){
            scores.push_back(it.second);
        }
        sort(scores.begin(), scores.end());
        for(auto num : scores){
            cout << num << " ";
        }
        cout << "\n";
    }
}
