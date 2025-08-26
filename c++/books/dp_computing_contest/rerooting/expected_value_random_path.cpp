/*
There is a weighted tree with n nodes 1..n and n − 1 edges. 
What is the expected value of the sum of a randomly chosen path.
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

vi dp;
vector<vector<pii>> g;

void dfs(int u, int p) {
    // rerooting
}

void solve() {
    int n; cin >> n;
    g.assign(n, vector<pii>());
    dp.assign(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    // implement rerooting
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}