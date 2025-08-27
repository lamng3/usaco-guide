// problem url: https://codeforces.com/contest/2132/problem/B
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

void solve() {
    ll n; cin >> n;
    vl ans;
    ll m = 10;
    for (int i = 1; i <= 18; i++) {
        ll g = m + 1;
        if (n % g == 0) ans.push_back(n / g);
        m *= 10;
    }
    cout << ans.size() << '\n';
    for (int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << (i == 0 ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}