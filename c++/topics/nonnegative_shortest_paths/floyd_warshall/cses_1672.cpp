// problem url: https://cses.fi/problemset/task/1672
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector< vector<ll> > vll;

const ll INF = 2e18;

int n, m, q;

void solve() {
    cin >> n >> m >> q;
    vll d(n, vl(n, INF));
    for (int i = 0; i < n; i++) d[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        if (c < d[a][b]) d[a][b] = d[b][a] = c;
    }
    // floyd-warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = d[j][i] = min(
                    d[i][j],
                    d[i][k] + d[k][j]
                );
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        ll w = d[a][b] == INF ? -1 : d[a][b];
        cout << w << '\n';
    }
}

int main() {
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}