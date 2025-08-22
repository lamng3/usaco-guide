/*
Modular Multiplicative Inverse

"(a/b) mod m = ((a mod m) / (b mod m)) mod m" not always hold.

We can use modular multiplicative inverse b^-1 that satisfies (b^-1 * b) mod m = 1.
Therefore, "(a/b) mod m = (a * b^-1) mod m = ((a mod m) * (b^-1 mod m))" (by multiplication rule).

We can use Fermat Little Theorem to calculate this. a^{p-1} mod p = 1.
We can also use Extended Euclidean Algorithm to calculate this.

Inspired from bqi343/cp-notebook
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

const int MOD = 1e9+7;
const int MAXN = 1e6;

vi invs, fac, ifac;

void precompute_factorials(int n) {
    /*
        calculate inverse factorials and factorials
            with euclidean division
    */
    invs.resize(n+1), fac.resize(n+1), ifac.resize(n+1);
    invs[1] = fac[0] = ifac[0] = 1;
    for (int i = 2; i <= n; i++) invs[i] = int(MOD - (ll)MOD/i * invs[MOD%i] % MOD);
    for (int i = 1; i <= n; i++) {
        fac[i] = int((ll)fac[i-1] * i % MOD);
        ifac[i] = int((ll)ifac[i-1] * invs[i] % MOD);
    }
}

int nck(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return (ll) fac[n] * ifac[n-k] % MOD * ifac[k] % MOD;
}

/*
Problem: Given a and b, calculate nCk(a, b).
Test Cases:
5
5 2
6 3
10 5
10 10
100 50
Expected:
10
20
252
1
538992043
*/
void solve() {
    int a, b; cin >> a >> b;
    cout << nck(a, b) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    precompute_factorials(MAXN);
    int tt = 1; 
    cin >> tt;
    while (tt--) solve();
    return 0;
}

