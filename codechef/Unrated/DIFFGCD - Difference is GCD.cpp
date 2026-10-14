#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long ans = 0;
        long long i = 1;

        while (i < n) {
            long long x = n / i;
            long long j = n / x;

            ans += (x - 1) * (j - i + 1);
            i = j + 1;
        }

        cout << ans << endl;
    }

    return 0;
}