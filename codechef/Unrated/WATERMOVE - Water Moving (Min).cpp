#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        std::vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        cout << max(v[n-1], v[0]+v[1]) << endl;
    }
}
