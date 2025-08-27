// problem url: https://codeforces.com/contest/2132/problem/C2
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

const ll maxcoins = (ll) 2e18;

ll n, k;
vl pre, ds;

void build_powers(ll n) {
    pre.push_back(1);
    while (pre.back() <= n / 3) {
        pre.push_back(pre.back() * 3);
    }
}

void build_deals() {
    ds.assign(pre.size(), 0);
    for (int i = 0; i < pre.size(); i++) {
        ll base = 3 * pre[i];
        ll extra = i > 0 ? i * pre[i-1] : 0;
        ds[i] = base + extra;
    }
}

int check(ll coins) {
    /*
    not the usual greedy of taking from largest to smallest
    */
}

ll find() {
    ll l = -1, r = maxcoins;
    while (r - l > 1) {
        ll m = (r + l) >> 1;
        if (check(m)) r = m;
        else l = m;
    }
    return r;
}

void solve() {
    cin >> n >> k;
    build_powers(n);
    build_deals();
    ll ans = find();
    cout << (ans == maxcoins ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}