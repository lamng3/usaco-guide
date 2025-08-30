// problem url: https://leetcode.com/problems/matchsticks-to-square/description/
// difficulty: medium
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi ms(n); ll s = 0;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        ms[i] = m; s+=m;
    }
    if (s%4) { cout << 0 << '\n'; return; }
    ll x = s/4;
    int FULL = 1 << n;
    vi dp(FULL, 0);
    for (int mask = 0; mask < FULL; mask++) {
        ll c = 0;
        for (int i = 0; i < n; i++) if ((mask&(1<<i))) c += ms[i];
        dp[mask] = (c==x);
    }
    for (int mask = 0; mask < FULL; mask++) {
        for (int submask = mask; submask; submask=(submask-1)&mask) {
            int subset = submask ^ mask;
            dp[mask] |= (dp[subset]&dp[submask]);
        }
    }
    cout << dp[FULL-1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}