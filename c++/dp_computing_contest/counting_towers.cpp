/*
Source: CSES
Problem url: https://cses.fi/alon/task/2413
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9+7;

int main() {
    int tt; cin >> tt;
    
    int q[tt], maxn = 0;
    for (int i = 0; i < tt; i++) {
        cin >> q[i];
        maxn = max(maxn, q[i]);
    }
    
    vector<ll> sep(maxn+1, 0), join(maxn+1, 0);
    sep[1] = join[1] = 1;
    for (int i = 2; i <= maxn; i++) {
        sep[i] = (4 * sep[i-1] + join[i-1]) % mod;
        join[i] = (2 * join[i-1] + sep[i-1]) % mod;
    }

    for (int n : q) {
        cout << ((join[n] + sep[n]) % mod) << '\n';
    }
}