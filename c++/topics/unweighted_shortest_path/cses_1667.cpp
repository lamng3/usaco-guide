// problem url: https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;
typedef pair<int,int> pii;

const int INF = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vii g(n, vi());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi d(n, INF); d[0] = 0;
    vi p(n, -1); p[0] = -1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (d[v] == INF) {
                d[v] = d[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }
    if (d[n-1] == INF) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    vi path;
    for (int v = n-1; v != -1; v = p[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    int k = (int) path.size();
    cout << k << '\n';
    for (int i = 0; i < k; i++) cout << (path[i]+1) << (i==k?'\n':' ');
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