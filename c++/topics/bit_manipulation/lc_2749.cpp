// problem url: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/
// difficulty: medium
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
bit manipulation
count whether after k operations of -y, x can be represented as sum of powers of 2
*/
void solve() {
    ll x, y; cin >> x >> y;
    if (x == 0) { cout << 0 << '\n'; return; }
    for (int k = 1; k <= 60; k++) {
        if (__builtin_popcountll(x-k*y) <= k && k <= x-k*y) {
            cout << k << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}