#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    long long a, b; cin >> a >> b;
	    if(a == b) cout << -1 << endl;
	    else{
	        int cnt = 0;
	        long long diff = abs(a -b);
	        for(long long i = 1; i*i <= diff; i++){
	            if((a-1)%i == (b-1)%i){
	                cnt++;
	                if(i * i != diff){
	                cnt++;
	                }
	            }
	        }
	        cout << cnt << endl;
	    }
	}
}
