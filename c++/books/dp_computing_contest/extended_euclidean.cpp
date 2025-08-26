/*
Bezout Lemma: g = gcd(a, b) then there exists x and y where ax + by = g

ax + by is a Linear Diophantine Equation.

We can use Extended Euclidean Algorithm to find inverse. 
Note that a * a^{-1} mod m = 1. Therefore, a * a^{-1} - km = 1
Let a^{-1} = x, m = b, -k = y. We have ax + by = gcd(a, b) = gcd(a, m) = 1.

Note that a * a^{-1} mod m = 1 then gcd(a, m) = 1. 

Thus, we can solve ax + by = 1 as this is a Linear Diophantine Equation. 
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, ll>

const int MOD = 1e9+7;

ll euclid(ll a, ll b) {
    if (b == 0) return a;
    return euclid(b, a % b);
}

int euclid_inv(int x, int m) {
    /*
        Calculate Inversion with Euclidean Division
        Supposed a prime modulus m > a. 
        m = ka + r  with k = m / a and r = m % a
        0 = ka + r mod m
        r = -ka mod m
        r * a^{-1} = -k mod m
        a^{-1} = -k / r = -k * inv(r) mod m
    */
    return x <= 1 ? x : m - (ll) m / x * euclid_inv(m % x, m) % m;
}

pl extend_euclid(ll a, ll b) {
    /*
        Calculate Inversion with more information.
        We find x and y such that ax + by = gcd(a, b).
        Let g = gcd(a, b). Therefore, ax + by = g.
        The Euclidean algorithm ends when a = g and b = 0. Then (x, y) = (1, 0). 
        We need to recursively trace back from {1, 0} to find out how (x, y) changes
            from (a, b) to (b, a mod b).
        Supposed we found (x1, y1) for (b, a mod b). We have:
            b * x1 + (a mod b) * y1 = g
        Let a mod b = a - (a/b) * b. We have:
            b * x1 + (a - (a/b) * b) * y1 = g
            a * y1 + b * (x1 - (a/b) * y1) = g
        Thus, the transition is:
            x = y1 
            y = x1 - (a/b) * y1
        We now trace back from {1, 0}
    */
   if (b == 0) return {1, 0};
   pl p = extend_euclid(b, a % b);
   return {p.second, p.first - (a/b) * p.second};
}

int extend_euclid_inv(int x, int m) {
    ll a = x % m; 
    a += a < 0 ? m : 0;
    pl p = extend_euclid(a, (ll) m);
    ll g = a * p.first + (ll) m * p.second;
    if (g != -1) return -1; // no inverse
    ll inv = p.first % m;
    inv += inv < 0 ? m : 0;
    return (int) inv;
}

void solve() {

}

int main() {
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}