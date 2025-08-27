// problem url: https://codeforces.com/contest/2132/problem/C1
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll log3(ll x) {
    int s = 0;
    while (x > 0) {
        s++;
        x /= 3;
    }
    return s+1;
}

ll binpow(ll a, ll b) {
    if (a == 0) return b == 0;
    ll s = 1;
    while (b) {
        if (b & 1) s *= a;
        a *= a;
        b >>= 1;
    }
    return s;
}

vl prepow(ll b, ll x) {
    vl s(x+1);
    for (int i = 0; i <= x; i++) s[i] = binpow(b, i);
    return s;
}

vl deals(ll n, ll lg3) {
    vl s;
    vl pre = prepow(3, lg3);
    for (int i = 0; i <= lg3; i++) {
        s.push_back(pre[i+1] + (i > 0 ? i * pre[i-1] : 0));
    }
    return s;
}

void solve() {
    ll n; cin >> n;
    
    ll lg3 = log3(n);
    vl pre = prepow(3, lg3);
    vl ds = deals(n, lg3);

    ll ans = 0;
    for (int i = ds.size()-1; i >= 0; i--) {
        if (n < pre[i]) continue;
        ll d = n / pre[i];
        ll r = n % pre[i];
        n = r;
        ans += d * ds[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}