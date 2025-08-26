/*
Source: Codeforces
Problem url: https://codeforces.com/contest/1236/problem/B?mobile=false
Problem name: B. Alice and the List of Presents
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9+7;

int modpow(ll a, ll b, int m) {
    if (a == 0) return b == 0;
    ll s = 1;
    while (b) {
        if (b & 1) s = (s * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return (int) s;
}

void solve() {
    int n, m; cin >> n >> m;
    int x = (modpow(2, m, MOD) - 1 + MOD) % MOD; // must exist in one box
    cout << modpow(x, n, MOD) << '\n';  
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}