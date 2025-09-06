// problem url: https://cses.fi/problemset/task/1679
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

void solve() {
    int n, m; cin >> n >> m;
    vii g(n, vi());
    vi indeg(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    vi ans; ans.reserve(n);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (int v : g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    int k = (int) ans.size();
    if (k < n) { cout << "IMPOSSIBLE" << '\n'; return; }
    for (int i = 0; i < k; i++) cout << (ans[i]+1) << (i == k ? '\n' : ' ');
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