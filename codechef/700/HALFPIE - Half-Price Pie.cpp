#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        int sum = 0;
        int mini = 9999;
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 0; i < n; i++){
            if(i > 0){
                mini = min(mini, v[i-1]+v[i]);
            }
            sum += v[i];
        }
        cout << sum - mini/2 << endl;
    }
}
