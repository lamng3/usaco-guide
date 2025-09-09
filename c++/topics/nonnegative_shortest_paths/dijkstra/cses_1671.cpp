// problem url: https://cses.fi/problemset/task/1671
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vp;
typedef vector< vp > vpp;

const ll INF = 2e18;

void solve() {
    int n, m; cin >> n >> m;
    vpp adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        ll c; cin >> c;
        a--; b--;
        adj[a].push_back(pl(b, c));
    }

    vl d(n, INF); d[0] = 0;
    vl processed(n,0);

    priority_queue< pl, vp, greater<pl> > pq;
    pq.push(pl(d[0], 0));

    while (!pq.empty()) {
        pl node = pq.top(); pq.pop();
        int u = (int) node.se;
        if (processed[u]) continue;
        processed[u] = 1;

        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i].fi;
            ll w = adj[u][i].se;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push(pl(d[v], v));
            }
        }
    }
    for (int i = 0; i < n; i++) cout << d[i] << (i==n-1?'\n':' ');
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