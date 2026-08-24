#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
	    std::vector<int> v(n);
	    for(int i = 0; i < n; i++){
	        cin >> v[i];
	    }
	    vector<int> diff;
	    int ans = 0;
	    for(int i = 0; i < n; i++){
	        int n0 = abs(v[i] - (i+1));
	        diff.push_back(n0);
	        if(n0 != 0) ans = n0;
	    }
	    if(ans == 0) cout << ans << endl;
	    else{
	        for(int i = 0; i < diff.size(); i++){
	            ans = gcd(ans, diff[i]);
	        }
	        cout << ans << endl;
	    }
	}
}
