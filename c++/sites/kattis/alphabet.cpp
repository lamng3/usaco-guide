// problem url: 
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve() {
    string s; cin >> s;
    int L = (int) s.size();
    vi a(L); for (int i = 0; i < L; i++) a[i] = s[i] - 'a';
    vi dp(L, 1);
    int mx = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        mx = max(mx, dp[i]);
    }
    cout << 26 - mx << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}