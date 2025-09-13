// problem url: https://codeforces.com/contest/2148/problem/E
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
    int n, k; cin >> n >> k;
    int mx = 0;

    vi a(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    mx = max(mx, n);

    vi f(mx+5,0); 
    for (int i = 0; i < n; i++) f[a[i]]++;

    vi chk(mx+5,0);
    for (int i = 1; i <= mx; i++) {
        if (f[i] % k) {
            cout << 0 << '\n';
            return;
        }
        chk[i] = f[i] / k;
    }

    /*
        check [L,R]
    */
   ll ans = 0;
    vi cnt(mx+5,0);
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && cnt[a[j]] < chk[a[j]]) {
            cnt[a[j]]++;
            j++;
        }
        ans += j - i; // avoid empty by not taking j - i + 1
        cnt[a[i]]--;
    }
    cout << ans << '\n';
}

int main() {
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}