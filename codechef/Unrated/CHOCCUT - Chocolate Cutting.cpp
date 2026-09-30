#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        if (N % 2 == 0 || M % 2 == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}