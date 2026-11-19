#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]) cnt++;
        }
        if((n - cnt) <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
