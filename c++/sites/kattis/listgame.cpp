// problem url: https://open.kattis.com/problems/listgame
// difficulty: easy
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve() {
    int x; cin >> x;
    int curx = x, ans = 0;
    for (int p = 2; p * p <= x; p++) {
        while (curx % p == 0) {
            ans++;
            curx /= p;
        }
    }
    if (curx > 1) ans++;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}