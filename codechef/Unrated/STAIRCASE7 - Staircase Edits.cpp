#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        unordered_map<int, int> freq;
        int maxi = -1;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            int key = x - i;
            freq[key]++;
            maxi = max(maxi, freq[key]);
        }
        cout << n - maxi << endl;
    }
}
