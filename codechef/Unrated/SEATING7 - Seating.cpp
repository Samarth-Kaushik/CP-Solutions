#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<bool> occupied(N + 1, false);
        for (int i = 0; i < M; i++) {
            int x;
            cin >> x;
            occupied[x] = true;
        }
        for (int person = 0; person < K; person++) {
            for (int seat = 1; seat <= N; seat++) {
                if (!occupied[seat]) {
                    cout << seat << " ";
                    occupied[seat] = true;
                    break;
                }
            }
        }

        cout << '\n';
    }

    return 0;
}