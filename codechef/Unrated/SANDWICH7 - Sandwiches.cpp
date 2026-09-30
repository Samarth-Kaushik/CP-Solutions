#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int b, h, c;
    cin >> b >> h >> c;
    int n = b/2;
    int m = h + c;
    cout << min(n, m) << endl;
}
