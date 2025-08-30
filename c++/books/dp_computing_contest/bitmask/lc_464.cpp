// problem url: https://leetcode.com/problems/can-i-win/description/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve() {
    int mci, dt; cin >> mci >> dt;
    if (dt < mci) { cout << 1 << '\n'; return; }
    if (mci * (mci+1) / 2 < dt) { cout << 0 << '\n'; return; }
    int FULL = 1 << mci;
    vi dp(FULL, 0);
    vi masksum(FULL, 0);
    for (int mask = 0; mask < FULL; mask++) {
        for (int i = 1; i <= mci; i++) {
            if ((mask&(1<<(i-1)))) {
                masksum[mask] += i;
            }
        }
    }
    // dp[mask] = current player can force a win
    for (int mask = FULL-1; mask >= 0; mask--) {
        if (masksum[mask] >= dt) continue;
        for (int i = 1; i <= mci; i++) {
            if ((mask&(1<<(i-1)))) continue;
            // if can force a win
            // or future state the other player loses
            dp[mask] |= ((masksum[mask]+i>=dt)|(dp[mask|(1<<(i-1))]==0));
        }
    }
    cout << (dp[0] == 0 ? 0 : 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1; 
    // cin >> tt;
    while (tt--) solve();
    return 0;
}