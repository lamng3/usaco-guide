/*
Source: CSES
Problem url: https://cses.fi/alon/task/2413
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tt; 
    cin >> tt;
    vector<int> qs(tt);
    int maxn = 0;
    for (int i = 0; i < tt; ++i) {
        cin >> qs[i];
        maxn = max(maxn, qs[i]);
    }

    vector<ll> join(maxn + 1, 0), sep(maxn + 1, 0);
    join[1] = sep[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        sep[i]  = (4 * sep[i-1] + join[i-1]) % MOD;
        join[i] = (2 * join[i-1] + sep[i-1]) % MOD;
    }

    for (int n : qs) {
        cout << ((join[n] + sep[n]) % MOD) << '\n';
    }

    return 0;
}