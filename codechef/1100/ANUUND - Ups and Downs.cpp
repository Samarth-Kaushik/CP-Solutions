#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
	    std::vector<int> v(n);
	    for(int i = 0; i < n; i++) cin >> v[i];
	    sort(v.rbegin(), v.rend());
	    for(int i = 0; i < n - 1; i += 2){
	        swap(v[i], v[i+1]);
	    }
	    for(int num : v) cout << num << " ";
	    cout << endl;
	}
}
