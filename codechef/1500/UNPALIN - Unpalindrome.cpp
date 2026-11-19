#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        std::vector<int> v(n) ;
        vector<bool> present(n+1, false);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            present[v[i]] = true;
        }
        bool isPalin = true;
        for(int i = 0; i < n/2; i++){
            if(v[i] != v[n-i-1]){
                isPalin = false;
                break;
            }
        }
        if(isPalin){
            cout << "NO" << endl;
        }
        else{
            bool isPoss = false;
            sort(v.begin(), v.end());
            for(int i = 1; i <= n; i++){
                if(!present[i]){
                    cout << "YES " << i << endl;
                    isPoss = true;
                    break;
                }
            }
            if(!isPoss){
                cout <<"YES " <<1 << endl;
            }
        }
    }
}
