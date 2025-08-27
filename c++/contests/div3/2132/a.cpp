// problem url: https://codeforces.com/contest/2132/problem/A
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string a; cin >> a;
    int m; cin >> m;
    string b; cin >> b;
    string c; cin >> c;
    for (int i = 0; i < m; i++) {
        char o = c[i];
        if (o == 'V') a.insert(0, 1, b[i]);
        else a.push_back(b[i]);
    }
    cout << a << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}